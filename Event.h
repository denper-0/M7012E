#pragma once
#include <string>
#include <vector>
//#include "MyLeap.h"
//#include "RoomState.h"
//#include "PlayerState.h"
//#include "Room.h"
class MyLeap;
class RoomState;
class PlayerState;
class Room;
enum MyLeapAction;

enum OnEventAction {
	ON_EVENT_NO_ACTION,
	ON_EVENT_ITERATE_ITEMS_LEFT,
	ON_EVENT_ITERATE_ITEMS_RIGHT,
	ON_EVENT_ITERATE_FACING_LEFT,
	ON_EVENT_ITERATE_FACING_RIGHT
};

class Event
{
private:
	MyLeapAction action;
	std::string eventText;
	PlayerState* cur_PS;
	PlayerState* new_PS;
	RoomState* cur_RS;
	RoomState* new_RS;
	bool moveToNextRoom;
	bool barelyEscapable;
	Room* barelyEscapableRoom;
	std::vector<OnEventAction> eventActions;

public:
	Event(MyLeapAction, PlayerState*, RoomState*, PlayerState*, RoomState*, std::string);
	~Event(void);
	void setText(std::string);
	std::string getText();
	void setPlayerState(PlayerState* currentRS, PlayerState* newRS);
	void setRoomState(RoomState* currentRS, RoomState* newRS);
	PlayerState* getNewPlayerstate();
	RoomState* getNewRoomstate();
	PlayerState* getCurrentPlayerstate();
	RoomState* getCurrentRoomstate();
	MyLeapAction getAction();
	bool getMoveToNextRoom();
	void setMoveToNextRoom(bool isOnThisEvent);
	bool isBarelyEscapable();
	void setBarelyEscapable(Room *barelyEscapableRoom);
	Room* Event::getBarelyEscapableRoom();
};

