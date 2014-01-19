#pragma once

#include "Leap.h"
//using namespace Leap;
#include <vector>
#include <algorithm>
#include <iostream>


/*
open door:
 grep+pull or grep+push

pick up item:
 grep+pull up

open inventory:
 turn palm upwards
browse items:
 swipe while palm upsidedown
select item:
 grep

navigate: 
 left: swipe left
 right: swipe right
 forward: poke

HP = FRIENDS IN PARTY! :D


future MyLeapAction's:

Number of fingers
palms?
 grep
 release

circle <direction><velocity><radius>
 circle both hands <directrion><velocity><radius> <direction><velocity><radius>
swipe <direction><velocity>
 swipe both hands <directrion><velocity><direction><velocity>
screen taps
key taps
no movement, but hand is visable
NOTHING = nothing is visable


*/
enum MyLeapAction {
	SWIPE_RIGHT,
	SWIPE_LEFT,
	SWIPE_UP,
	SWIPE_DOWN,
	SWIPE_FORWARD,
	SWIPE_BACKWARD,
	NOT_CONNECTED, 
	NOTHING, 
	RANDOMSHIT,
	SCREEN_TAP,
	CIRCLE_CLOCKWISE,
	CIRCLE_COUNTER_CLOCKWISE,
	KEY_TAP,
	PALM_UP
};

class MyLeap
{
public:
	int64_t lastProcessedFrameID;
	Leap::Controller controller;

/**
 * @breif constructor for the leap motion controller interface
 */
	MyLeap(void);
/**
 * @breif descructor
 */
	~MyLeap(void);
/**
 * @breif searches for first acurence of MyLeapAction in the past until we have searched there before. 
 * @param float how far back in the past the searching goes
 * @param vector<MyLeapAction> what actions we are searching for
 * @return MyLeapAction what action was found
 */
	MyLeapAction getAction(float backMs, std::vector<MyLeapAction> actionList);
private:
/**
 * @breif checks if action is in adtionlist
 * @param MyLeapAction single action we are seraching for
 * @param vector<MyLeapAction> actions we are searching throught
 * @return boolean success or failure
 */
	bool actionIsInList(MyLeapAction action, std::vector<MyLeapAction> actionList);
/**
 * @breif processes the one frame in search of a action
 * @param Frame we are search thought
 * @param vector<MyLeapAction> what actions we are searching for
 * @return MyLeapAction what action was found
 */
	MyLeapAction MyLeap::processFrame( Leap::Frame frame, std::vector<MyLeapAction> actionList );
};

