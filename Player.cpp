#include "Player.h"


Player::Player(void) {
	this->facing = 0;
}

Player::~Player(void) {
	//?? memoryleeekekekes?
}

int Player::getFacing() {
	return facing;
}
void Player::setFacing(int facing) {
	this->facing = facing;
}