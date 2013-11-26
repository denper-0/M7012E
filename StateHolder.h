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
	virtual void overwrite(State s) = 0; // must be implemented
	virtual bool isEqual(State s) = 0; // must be implemented
private:
	State currentState;
};

