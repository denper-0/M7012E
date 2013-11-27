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

void Player::overWrite(State* s) {

}
bool Player::isEqual(State* s) {
	return false;
}