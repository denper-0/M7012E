#pragma once
#include <vector>
//#include "State.h"
#include <iostream>
//using namespace std;
#include "State.h"


/**
 * @breif playerstate holds all proprtys for the player object so it easely can be compered and overwritten. 
 */
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
/**
 @breif returns facing of player
 @returns int facing of player 
 */
	int getFacing(void);
/**
 @breif sets facing of player
 @param int f facing of player 
 */
	void setFacing(int f);
/**
 @breif Sets the current item selected by the player
 @param int itemId items id
 */
	void setCurrentItemSelected(int itemId);
/**
 @breif Sets the current item selected by the player
 @retun int currentItemSelected items id
 */
	int getCurrentItemSelected();
/**
 @breif gets WTF facing of player
 @param int f facing of player 
 */
	int getMaxFacing();
};

