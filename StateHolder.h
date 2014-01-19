#pragma once
//#include "State.h"
class State;

/**
 * @breif Abstract interface for manipulating states
 */
class StateHolder
{
public:

/**
 * @breif constructor
 */
	StateHolder(void);
/**
 * @breif destructor
 */
	~StateHolder(void);
/**
 * @breif Abstract method for overwriteing the current state with fetched state, the secound state is for aditional nestled properties both states have. 
 * @param State* s state to compere with
 * @param State* s state that have nestled properies together with current state. 
 */
	virtual void overWrite(State* s, State* s2) = 0; // must be implemented
/**
 * @breif Abstract method for compering the current state with fetched state, the secound state is for aditional nestled properties both states have. Default valies (NULL) will be overlooked
 * @param State* s state to compere with
 * @param State* s state that have nestled properies together with current state. 
 * @return bool true if equal, else false
 */
	virtual bool isEqual(State* s, State* s2) = 0; // must be implemented
/**
 * @breif Abstract method for getting the state from the stateholder. 
 * @return State
 */
	virtual State* getState() = 0; // must be implemented
private:
	State* currentState;
};

