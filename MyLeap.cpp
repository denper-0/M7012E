#include "MyLeap.h"

MyLeap::MyLeap(void)
{
	
	controller.enableGesture(Leap::Gesture::TYPE_CIRCLE);
	controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Leap::Gesture::TYPE_SWIPE);
	lastProcessedFrameID = 0;
}

MyLeapAction MyLeap::getAction(float backMs, std::vector<MyLeapAction> actionList)
{
	// if not connected
	MyLeapAction ret = NOT_CONNECTED;
	if( !controller.isConnected()) {
		return ret;
	}
	ret = NOTHING;
	
	// default hold time
	if(backMs == 0) {
		backMs = 1000;
	}

	Leap::Frame currentFrame = controller.frame();
	Leap::Frame firstFrame = currentFrame;
	int64_t currentID = currentFrame.id();
	float instantaneousFrameRate = currentFrame.currentFramesPerSecond();
    
	// foreach frame since last parsed frame
	for( int history = 0; history < currentID - lastProcessedFrameID; history++)
    {
		currentFrame = controller.frame(history);
        ret = processFrame( currentFrame, actionList );

		// return if acceptable action was found
		if(ret != NOTHING && ret != RANDOMSHIT) {
			// ..if action is in actionList i.e we may return it
			if(std::find(actionList.begin(), actionList.end(), ret) != actionList.end()) {
				return ret;
			}
		}

		// return if we have checked relevant history spec. by BackMs
		if((currentFrame.timestamp() - firstFrame.timestamp()) > backMs || history > 1000) {
			return ret;
		}
    }

    lastProcessedFrameID = currentID;
	return ret;
}


MyLeapAction MyLeap::processFrame( Leap::Frame frame, std::vector<MyLeapAction> actionList )
{
    if( frame.id() == lastProcessedFrameID ) return NOTHING;

	// if not hands or no tools or no fingers where in this frame nothing is. 
	if( frame.hands().count() == 0 || frame.pointables().count() == 0 ) return NOTHING;

	// if something is visable the user is doing something random, not random. 
	MyLeapAction ret = RANDOMSHIT;

	std::vector<float> directions;

	// only check gestures if needed! (list all gesture based MyLeapActions)
	if(actionIsInList(SWIPE_RIGHT, actionList)
		|| actionIsInList(SWIPE_LEFT, actionList)
		|| actionIsInList(SWIPE_UP, actionList)
		|| actionIsInList(SWIPE_DOWN, actionList)
		|| actionIsInList(SWIPE_FORWARD, actionList)
		|| actionIsInList(SWIPE_BACKWARD, actionList)
		|| actionIsInList(SCREEN_TAP, actionList)
		|| actionIsInList(CIRCLE_CLOCKWISE, actionList)
		|| actionIsInList(CIRCLE_COUNTER_CLOCKWISE, actionList)
		|| actionIsInList(KEY_TAP, actionList)) {
		
		// Get gestures
		const Leap::GestureList gestures = frame.gestures();

		// foreach gesture
		for (int g = 0; g < gestures.count(); ++g) {

			Leap::Gesture gesture = gestures[g];

			// SWIPE
			if(actionIsInList(SWIPE_RIGHT, actionList)
				|| actionIsInList(SWIPE_LEFT, actionList)
				|| actionIsInList(SWIPE_UP, actionList)
				|| actionIsInList(SWIPE_DOWN, actionList)
				|| actionIsInList(SWIPE_FORWARD, actionList)
				|| actionIsInList(SWIPE_BACKWARD, actionList)) {

				// if it is a swipe gesture
				if(gesture.type() == Leap::Gesture::TYPE_SWIPE) {
			
					Leap::SwipeGesture swipe = gesture;

					// if the gesture is in progress. 
					if(gesture.state() == Leap::Gesture::STATE_UPDATE) {

						// need to figure out what direction is moste dominent
						if(abs(swipe.direction().x) > abs(swipe.direction().y) && abs(swipe.direction().x) > abs(swipe.direction().z)) {
							// x is dominant movement direction
							if(swipe.direction().x > 0) {
								return SWIPE_RIGHT;
							} else {
								return SWIPE_LEFT;
							}
						} else if(abs(swipe.direction().y) > abs(swipe.direction().x) && abs(swipe.direction().y) > abs(swipe.direction().z)) {
							// y is dominant movement direction
							if(swipe.direction().y > 0) {
								return SWIPE_UP;
							} else {
								return SWIPE_DOWN;
							}
						} else if(abs(swipe.direction().z) > abs(swipe.direction().x) && abs(swipe.direction().z) > abs(swipe.direction().y)) {
							// z is dominant movement direction
							if(swipe.direction().z > 0) {
								return SWIPE_BACKWARD;
							} else {
								return SWIPE_FORWARD;
							}
						} else {
							// wtf, user swiped super diagonaled perfect stuff! xD
						}

					}
					/*
					std::cout << "Swipe id: " << gesture.id()
						<< ", state: " << gesture.state()
						<< ", direction: " << swipe.direction()
						<< ", speed: " << swipe.speed() << std::endl;
					*/
				}
			}
			
			if(actionIsInList(SCREEN_TAP, actionList)) {
				if(gesture.type() == Leap::Gesture::TYPE_SCREEN_TAP) {
					Leap::ScreenTapGesture tap = gesture;
					if(gesture.state() == Leap::Gesture::STATE_UPDATE) {
						return SCREEN_TAP;
					}
				}
			}
			
			if(actionIsInList(CIRCLE_CLOCKWISE, actionList)
				|| actionIsInList(CIRCLE_COUNTER_CLOCKWISE, actionList)) {
				if(gesture.type() == Leap::Gesture::TYPE_CIRCLE) {
					Leap::CircleGesture circle = gesture;
					if(gesture.state() == Leap::Gesture::STATE_UPDATE) {
						if(circle.progress() >= 1) {
							if (circle.pointable().direction().angleTo(circle.normal()) <= Leap::PI/2) {
								//clockwise
								return CIRCLE_CLOCKWISE;
							} else {
								return CIRCLE_COUNTER_CLOCKWISE;
							}
						}
					}
				}
			}

			if(actionIsInList(KEY_TAP, actionList)) {
				if(gesture.type() == Leap::Gesture::TYPE_KEY_TAP) {
					Leap::KeyTapGesture keytap = gesture;
					if(gesture.state() == Leap::Gesture::STATE_UPDATE) {
						return KEY_TAP;
					}
				}
			}
		}
		
		if(actionIsInList(PALM_UP, actionList)) {
			Leap::HandList hands = frame.hands();
			Leap::Hand hand;
			for(Leap::HandList::const_iterator hl = frame.hands().begin(); hl != frame.hands().end();) {
				hand = *hl;
				
			}
		}
	}

    lastProcessedFrameID = frame.id();
	return ret;
}

bool MyLeap::actionIsInList(MyLeapAction action, std::vector<MyLeapAction> actionList) {
	return std::find(actionList.begin(), actionList.end(), action) != actionList.end();
}

MyLeap::~MyLeap(void)
{
}
