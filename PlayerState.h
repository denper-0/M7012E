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
	int facing;
	int HP;
public:
	PlayerState(int facing = 0);
	~PlayerState(void);
};

