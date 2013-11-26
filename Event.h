#pragma once
#include <iostream>
#include "MyLeap.h"
#include "RoomState.h"
#include "PlayerState.h"
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
	void setText(string);
	string getText();
	void setPlayerState(PlayerState currentRS, PlayerState newRS);
	void setRoomState(RoomState currentRS,RoomState newRS);
	PlayerState getNewPlayerstate();
	RoomState getNewRoomstate();
	PlayerState getCurrentPlayerstate();
	RoomState getCurrentRoomstate();
	MyLeapAction getAction();
};

