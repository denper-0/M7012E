#pragma once
#include "StateHolder.h"
#include <vector>
#include <iostream>
//#include "Room.h"
using namespace std;

class Player : public StateHolder
{
public:
	Player(void);
	~Player(void);
	int getFacing();
	void setFacing(int facing);
	string getInventory();
	void addToInventory(int);
	void removeToInventory(int);
	virtual void overwrite(State s) = 0; // must be implemented
	virtual bool isEqual(State s) = 0; // must be implemented

private:
	int facing;
	int HP;
	vector<int> inventory;

};

