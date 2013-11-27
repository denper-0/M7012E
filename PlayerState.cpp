#include "PlayerState.h"


PlayerState::PlayerState(int f)
{
	facing = f;
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