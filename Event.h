#pragma once
#include <iostream>
#include "MyLeap.h"
//#include "Room.h"
using namespace std;

class Event
{
private:
	MyLeapAction action;
	string eventText;
	PlayerState cur_PS;
	PlayerState new_PS;
	RoomState cur_RS;
	RoomState new_RS;
public:
	Event(MyLeapAction, PlayerState, PlayerState, RoomState, RoomState, string);
	~Event(void);
	string setEventText(string);
	string getEventText();
	void setPlayerstate(PlayerState, PlayerState);
	void setRoomstate(RoomState, RoomState);
};

