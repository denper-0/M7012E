#pragma once
#include <vector>
#include <string>
#include "State.h"

class Room;

enum ROOM_DIRECTIONS { NORTH, EAST, SOUTH, WEST, NO_DIRECTION };

enum NextRoomState {
	NEXT_ROOM_IS_NULL,
	NEXT_ROOM_IS_LOCKED,
	NEXT_ROOM_IS_UNLOCKED
};

class RoomState : public State
{
private: 
	std::vector<int> items;
	std::vector<int> itemsToRemove;
	std::vector<Room*> doors;
	std::vector<std::string> description;
	int roomIsLocked;
public:
	RoomState(void);
	~RoomState(void);
	void setDesc(int i, std::string s);
	std::string getDesc(int i);
	void setDoor(int i, Room* r);
	Room* getDoor(int i);
	int getRoomIsLocked();
	void setRoomIsLocked(int);
};