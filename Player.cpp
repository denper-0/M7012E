#include "Player.h"


Player::Player(void) {
	facing = 0;
	HP = 10;
}

Player::~Player(void) {
	//?? memoryleeekekekes?
}

int Player::getFacing() {
	return this->facing;
}
void Player::setFacing(int facing) {
	this->facing = facing;
}