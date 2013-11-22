#pragma once

#include "Leap.h"
using namespace Leap;
#include <vector>
#include <algorithm>
#include <iostream>

enum MyLeapAction { ROTATE_LEFT, ROTATE_RIGHT, NOT_CONNECTED, NOTHING, RANDOMSHIT };

class MyLeap
{
public:
	MyLeap(void);
	~MyLeap(void);
	MyLeapAction getAction(float backMs, std::vector<MyLeapAction> actionList);
private:
	int64_t lastProcessedFrameID;
	Leap::Controller controller;
	MyLeapAction MyLeap::processFrame( Leap::Frame frame, std::vector<MyLeapAction> actionList );
};

