#pragma once
#include <vector>
//#include "State.h"
#include <iostream>
//using namespace std;
#include "State.h"


class PlayerState : public State
{
private: 
	std::vector<int> items;
	std::vector<int> itemsToRemove;
	int facing;
	int HP;
	int currentItemSelected;
	int maxFacing;
public:
	PlayerState(int facing = 4, int itemId = 0, int HP = 0);
	~PlayerState(void);
	int getFacing(void);
	void setFacing(int f);
	void setCurrentItemSelected(int itemId);
	int getCurrentItemSelected();
	int getMaxFacing();
};

