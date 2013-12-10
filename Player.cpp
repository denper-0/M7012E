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

void Player::setCurrentToNextItem(bool iterateUp) {
	int itemId = currentState->getCurrentItemSelected();
	std::vector<int> itemsInInventory = currentState->getItems();
	for (unsigned i=0; i<itemsInInventory.size(); i++) {
		if(itemsInInventory.at(i) == itemId) {
			if(iterateUp == true) {
				if(itemsInInventory.size() > i+1) {
					currentState->setCurrentItemSelected(itemsInInventory.at(i+1));
				} else {
					currentState->setCurrentItemSelected(itemsInInventory.at(0));
				}
			} else {
				if(i == 0) {
					currentState->setCurrentItemSelected(itemsInInventory.at(itemsInInventory.size()-1));
				} else {
					currentState->setCurrentItemSelected(itemsInInventory.at(i-1));
				}
			}
			return;
		}
	}
}