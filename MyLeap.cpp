#include "MyLeap.h"

MyLeap::MyLeap(void)
{
	
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Gesture::TYPE_SWIPE);
	lastProcessedFrameID = 0;
}

MyLeapAction MyLeap::getAction(float backMs, std::vector<MyLeapAction> actionList)
{
	MyLeapAction ret = NOT_CONNECTED;
	if( !controller.isConnected()) {
		return ret;
	}
	ret = NOTHING;
	Frame currentFrame = controller.frame();
	Frame firstFrame = currentFrame;
	int64_t currentID = currentFrame.id();
	float instantaneousFrameRate = currentFrame.currentFramesPerSecond();
    
	for( int history = 0; history < currentID - lastProcessedFrameID; history++)
    {
		currentFrame = controller.frame(history);
        ret = processFrame( currentFrame, actionList );

		// return if acceptable action was found
		if(ret != NOTHING && ret != RANDOMSHIT) {
			//
			if(std::find(actionList.begin(), actionList.end(), ret) != actionList.end()) {
				return ret;
			}
		}

		// return if we have checked relevant history spec. by BackMs
		if((currentFrame.timestamp() - firstFrame.timestamp()) > backMs) {
			return ret;
		}
    }

    lastProcessedFrameID = currentID;
	return ret;
}


MyLeapAction MyLeap::processFrame( Leap::Frame frame, std::vector<MyLeapAction> actionList )
{
    if( frame.id() == lastProcessedFrameID ) return NOTHING;
    
	// check only relevant spec. by actionList!
	// ... 

	// Get gestures
	const GestureList gestures = frame.gestures();
	for (int g = 0; g < gestures.count(); ++g) {
		Gesture gesture = gestures[g];
		switch (gesture.type()) {
			case Gesture::TYPE_SWIPE: {
				SwipeGesture swipe = gesture;

				if(gesture.state() == Leap::Gesture::STATE_STOP) {
					if(swipe.direction().x > 0) {
						//std::cout << "ROTATE_RIGHT";
						return ROTATE_RIGHT;
					} else {
						//std::cout << "ROTATE_LEFT";
						return ROTATE_LEFT;
					}
				}
				break;
				std::cout << "Swipe id: " << gesture.id()
					<< ", state: " << gesture.state()
					<< ", direction: " << swipe.direction()
					<< ", speed: " << swipe.speed() << std::endl;
				
				break;
			}
		}
	}

    lastProcessedFrameID = frame.id();
	return NOTHING;
}


MyLeap::~MyLeap(void)
{
}
