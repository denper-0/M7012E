#pragma once
//#include "StateHolder.h"
#include <vector>
#include <iostream>
//#include "Room.h"
//using namespace std;
#include "StateHolder.h"
#include "PlayerState.h"
class State;

class Player : public StateHolder
{
public:
	Player(void);
	~Player(void);
	int getFacing();
	void setFacing(int facing);
	std::string getInventory();
	void addToInventory(int, int);
	void removeFromInventory(int);
	void setCurrentToNextItem(bool);
	int getCurrentItem();
	virtual void overWrite(State* s); // must be implemented
	virtual bool isEqual(State* s); // must be implemented

private:
	std::vector<int> inventory;
	PlayerState* currentState;
};

