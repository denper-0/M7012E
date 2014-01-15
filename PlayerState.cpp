#include "PlayerState.h"


PlayerState::PlayerState(int f, int itemId, int HP)
{
	facing = f;
	if(itemId == 0) {
		items.push_back(itemId);
	}
	this->HP = HP;
	currentItemSelected = 0;
	maxFacing = 3;
}


PlayerState::~PlayerState(void)
{
}

/**
 @breif returns facing of player
 @returns int facing of player 
 */
int PlayerState::getFacing(void) {
	return facing;
}

/**
 @breif sets facing of player
 @param int f facing of player 
 */
void PlayerState::setFacing(int f) {
	facing = f;
}
/**
 @breif gets WTF facing of player
 @param int f facing of player 
 */
int PlayerState::getMaxFacing() {
	return maxFacing;
}

/**
 @breif Sets the current item selected by the player
 @param int itemId items id
 */
void PlayerState::setCurrentItemSelected(int itemId) {
	currentItemSelected = itemId;
}

/**
 @breif Sets the current item selected by the player
 @retun int currentItemSelected items id
 */
int PlayerState::getCurrentItemSelected() {
	return currentItemSelected;
}