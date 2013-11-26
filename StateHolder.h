#pragma once
#include "State.h";

/**
Abstract interface for manipulating states
*/
class StateHolder
{
public:
	StateHolder(void);
	~StateHolder(void);
	virtual void overwrite(State s) = 0;
	virtual bool isEqual(State s) = 0;
private:
	State currentState;
};

