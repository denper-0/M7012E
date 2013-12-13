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

int PlayerState::getFacing(void) {
	return facing;
}
void PlayerState::setFacing(int f) {
	facing = f;
}
int PlayerState::getMaxFacing() {
	return maxFacing;
}


void PlayerState::setCurrentItemSelected(int itemId) {
	currentItemSelected = itemId;
}
int PlayerState::getCurrentItemSelected() {
	return currentItemSelected;
}