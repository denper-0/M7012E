#pragma once
#include <list>
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

private:
	int facing;
	list<string> items;		//Kanske object senare
};

