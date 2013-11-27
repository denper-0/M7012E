#pragma once
#include <string>
//#include "MyLeap.h"
//#include "RoomState.h"
//#include "PlayerState.h"
//#include "Room.h"
class MyLeap;
class RoomState;
class PlayerState;
class Room;
enum MyLeapAction;

class Event
{
private:
	MyLeapAction action;
	std::string eventText;
	PlayerState cur_PS;
	PlayerState new_PS;
	RoomState cur_RS;
	RoomState new_RS;

public:
	Event(MyLeapAction, PlayerState, RoomState, PlayerState, RoomState, std::string);
	~Event(void);
	void setText(std::string);
	std::string getText();
	void setPlayerState(PlayerState currentRS, PlayerState newRS);
	void setRoomState(RoomState currentRS, RoomState newRS);
	PlayerState getNewPlayerstate();
	RoomState getNewRoomstate();
	PlayerState getCurrentPlayerstate();
	RoomState getCurrentRoomstate();
	MyLeapAction getAction();
};

