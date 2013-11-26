#pragma once
#include "Room.h"
#include "State.h"
#include <vector>
#include <string>


class RoomState : public State
{
private: 
	vector<int> items;
	vector<Room> doors;
	vector<string> description;

public:
	RoomState(void);
	~RoomState(void);
	void setDesc(int i, string s);
	string getDesc(int i);
	void setDoor(int i, Room r);
	Room getDoor(int i);
	
};