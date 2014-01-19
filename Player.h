#pragma once
//#include "StateHolder.h"
#include <vector>
#include <iostream>
//#include "Room.h"

#include "StateHolder.h"
#include "PlayerState.h"
#include <algorithm>
class State;

/**
 * @breif player object that holds its properties in its playerstate. 
 */
class Player : public StateHolder
{
private:
	PlayerState* currentState;
	int maxFacing;

public:
	Player(void);
	~Player(void);
/**
 @breif returns facing of player
 @returns int facing of player 
 */
	int getFacing();
/**
 @breif sets facing of player
 @param int f facing of player 
 */
	void setFacing(int facing);
	std::string getInventory();
/**
 @breif Add item to invetory
 @param int i where to put the item in inventory list
 @param int itemId what itemId to add to inventory
 */
	void addToInventory(int, int);
	void removeFromInventory(int);
/**
 @breif switches current item, if end of Inventory list or not
 @param bool iterateUp if it iterates up
 */
	void setCurrentToNextItem(bool);
/**
 @breif gets current item selected
 @return int current itemId selected
 */
	int getCurrentItem();
/**
 @breif overwrites this player's state with given playerstate, NULL IGNORES
 @param State* s playerstate to overwrite with
 @param State* s2 the Playerstate to know facing  (NOT USED)
 */
	virtual void overWrite(State* s, State* s2); 
/**
 @breif checks if this player's state is equal to the given playerstate
 @param State* s playerstate to compare with
 @param State* s2 the Playerstate to know facing (NOT uSED)
 @return boolean if equal true ELSE false
 */
	virtual bool isEqual(State* s,State* s2); 
/**
 @breif changes direction of the players facing
 @param bool iterateUp if it iterates up
 */
	void setCurrentToNextDirection(bool);
/**
 @breif gets current state of the player
 @return State* currentState state of the player
 */
	State* getState();

/**
 @breif gets current size of invenotry 
 @return int size of intentory list
 */
	int getInventorySize();

};

