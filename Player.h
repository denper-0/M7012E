#pragma once

#include <vector>
#include <iostream>
//#include "Room.h"
using namespace std;

class Player
{
public:
	Player(void);
	~Player(void);
	int getFacing();
	void setFacing(int facing);
	string getInventory();
	void addToInventory(int);
	void removeToInventory(int);
private:
	int facing;
	int HP;
	vector<int> inventory;

};

