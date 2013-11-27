#pragma once
#include <vector>
#include <string>
#include "State.h"

class Room;

class RoomState : public State
{
private: 
	std::vector<int> items;
	std::vector<Room*> doors;
	std::vector<std::string> description;

public:
	RoomState(void);
	~RoomState(void);
	void setDesc(int i, std::string s);
	std::string getDesc(int i);
	void setDoor(int i, Room* r);
	Room* getDoor(int i);
	
};