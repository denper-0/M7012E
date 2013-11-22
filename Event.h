#pragma once
#include <iostream>
#include "MyLeap.h"
//#include "Room.h"
using namespace std;

class Event
{
private:
	MyLeapAction a;
	string eventText;
	PlayerState cur_PS;
	PlayerState new_PS;
	RoomState cur_RS;
	RoomState new_RS;
public:
	Event(void);
	~Event(void);
	string setEventText(string);
	string getEventText();
	void setPlayerstate(PlayerState, PlayerState);
	void setRoomstate(RoomState, RoomState);
};

