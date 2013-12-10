#include "PlayerState.h"


PlayerState::PlayerState(int f, int itemId, int HP)
{
	facing = f;
	this->itemId = itemId;
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