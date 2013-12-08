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
	RANDOMSHIT 
};

class MyLeap
{
public:
	MyLeap(void);
	~MyLeap(void);
	MyLeapAction getAction(float backMs, std::vector<MyLeapAction> actionList);
private:
	bool actionIsInList(MyLeapAction action, std::vector<MyLeapAction> actionList);
	int64_t lastProcessedFrameID;
	Leap::Controller controller;
	MyLeapAction MyLeap::processFrame( Leap::Frame frame, std::vector<MyLeapAction> actionList );
};

