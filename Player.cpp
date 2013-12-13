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

void Player::overWrite(State* s, State* s2) {
	PlayerState* ps = static_cast<PlayerState*>(s); // typecast
	if(ps->getFacing() != 4) {
		currentState->setFacing(ps->getFacing());
	}
	if(ps->getCurrentItemSelected() != 0) {
		currentState->setCurrentItemSelected(ps->getCurrentItemSelected());
	}
	std::vector<int> items;
	for(size_t i =0; i < items.size(); i++) {
		if(ps->getItem(i) != NULL) {
			items = ps->getItems();
			if(std::find(items.begin(), items.end(), ps->getItem(i)) == items.end()) {
				currentState->setItem(currentState->getItems().size(), ps->getItem(i));
			}
		}
	}
}
bool Player::isEqual(State* s, State* s2) {
	PlayerState* ps = static_cast<PlayerState*>(s); // typecast
	if(currentState->getFacing() != ps->getFacing() && ps->getFacing() != 4) {
		return false;
	}
	if(ps->getCurrentItemSelected() != 0 && currentState->getCurrentItemSelected() != ps->getCurrentItemSelected()) {
		return false;
	}
	for(size_t i =0; i < currentState->getItems().size(); i++) {
		if(ps->getItem(i) != NULL && ps->getItem(i) != this->currentState->getItem(i)) {
			return false;
		}
	}
	return true;
}
State* Player::getState() {
	return currentState;
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

void Player::setCurrentToNextDirection(bool iterateUp) {
	int facing = currentState->getFacing();
	int maxFacing = currentState->getMaxFacing();
	if(iterateUp == true) {
		if(facing+1 > maxFacing) {
			currentState->setFacing(0);
			return;
		}
		facing = facing+1;
	} else {
		if(facing-1 < 0) {
			currentState->setFacing(3);
			return;
		}
		facing = facing-1;
	}
	currentState->setFacing(facing);
}

void Player::addToInventory(int i, int itemId) {
	currentState->setItem(i,itemId);
}

int Player::getCurrentItem() {
	return currentState->getCurrentItemSelected();
}