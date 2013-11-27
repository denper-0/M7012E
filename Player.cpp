#include "Player.h"


Player::Player(void) {
	currentState = new PlayerState(0);
}

Player::~Player(void) {
	//?? memoryleeekekekes?
}

int Player::getFacing() {
	return currentState->getFacing();
}
void Player::setFacing(int facing) {
	this->currentState->setFacing(facing);
}

void Player::overWrite(State* s) {
	PlayerState* ps = static_cast<PlayerState*>(s); // typecast
	if(ps->getFacing() != 4) {
		currentState->setFacing(ps->getFacing());
	}
}
bool Player::isEqual(State* s) {
	PlayerState* ps = static_cast<PlayerState*>(s); // typecast
	if(currentState->getFacing() != ps->getFacing() && ps->getFacing() != 4) {
		return false;
	}
	return true;
}