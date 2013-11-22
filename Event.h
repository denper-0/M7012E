#pragma once
#include <iostream>
#include "MyLeap.h"
//#include "Room.h"
using namespace std;

class Event
{
public:
	Event(void);
	~Event(void);
	MyLeapAction a;
	int facing;
};

