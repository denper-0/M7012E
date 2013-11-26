#pragma once
#include "Room.h"
#include <vector>
#include <iostream>
using namespace std;


class RoomState
{
private: 
	vector<int> items;
	vector<Room> doors;
	string description;

public:
	RoomState(void);
	~RoomState(void);
	void setDesc(string);
	string getDesc();
	void setDoors(int, Room);
	Room getDoors(int);
	
};