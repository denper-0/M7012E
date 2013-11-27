#pragma once
//#include "State.h"
class State;

/**
Abstract interface for manipulating states
*/
class StateHolder
{
public:
	StateHolder(void);
	~StateHolder(void);
	virtual void overWrite(State* s) = 0; // must be implemented
	virtual bool isEqual(State* s) = 0; // must be implemented
private:
	State* currentState;
};

