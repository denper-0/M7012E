#pragma once
//#include "StateHolder.h"
#include <vector>
#include <iostream>
//#include "Room.h"
//using namespace std;
class StateHolder;

class Player : public StateHolder
{
public:
	Player(void);
	~Player(void);
	int getFacing();
	void setFacing(int facing);
	std::string getInventory();
	void addToInventory(int);
	void removeToInventory(int);
	virtual void overwrite(State s) = 0; // must be implemented
	virtual bool isEqual(State s) = 0; // must be implemented

private:
	int facing;
	int HP;
	std::vector<int> inventory;

};

