#pragma once
#include <vector>
#include "State.h"
#include <iostream>
using namespace std;


class PlayerState : public State
{
private: 
	vector<int> items;
	int facing;
	int HP;
public:
	PlayerState(int facing = 0);
	~PlayerState(void);
	
	
};

