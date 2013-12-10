#include "PlayerState.h"


PlayerState::PlayerState(int f, int itemId, int HP)
{
	facing = f;
	items.push_back(itemId);
	this->HP = HP;
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


void PlayerState::setCurrentItemSelected(int itemId) {
	currentItemSelected = itemId;
}
int PlayerState::getCurrentItemSelected() {
	return currentItemSelected;
}