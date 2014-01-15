#include "Player.h"


Player::Player(void) {
	currentState = new PlayerState(0);
}

Player::~Player(void) {
	//?? memoryleeekekekes?
}
/**
 @breif returns facing of player
 @returns int facing of player 
 */
int Player::getFacing() {
	return currentState->getFacing();
}
/**
 @breif sets facing of player
 @param int f facing of player 
 */
void Player::setFacing(int facing) {
	this->currentState->setFacing(facing);
}

/**
 @breif overwrites this player's state with given playerstate, NULL IGNORES
 @param State* s playerstate to overwrite with
 @param State* s2 the Playerstate to know facing  (NOT USED)
 */
void Player::overWrite(State* s, State* s2) {
	PlayerState* ps = static_cast<PlayerState*>(s); // typecast
	if(ps->getFacing() != 4) {
		currentState->setFacing(ps->getFacing());
	}
	if(ps->getCurrentItemSelected() != 0) {
		currentState->setCurrentItemSelected(ps->getCurrentItemSelected());
	}

	// add items
	std::vector<int> items = ps->getItems();
	std::vector<int> currentPlayersItems;
	for(size_t i =0; i < items.size(); i++) {
		if(ps->getItem(i) != NULL) {
			currentPlayersItems = currentState->getItems(); // need to update secound time and rest of them!
			if(std::find(currentPlayersItems.begin(), currentPlayersItems.end(), ps->getItem(i)) == currentPlayersItems.end()) {
				currentState->setItem(currentState->getItems().size(), ps->getItem(i));
			}
		}
	}
}
/**
 @breif checks if this player's state is equal to the given playerstate
 @param State* s playerstate to compare with
 @param State* s2 the Playerstate to know facing (NOT uSED)
 @return boolean if equal true ELSE false
 */
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

/**
 @breif gets current state of the player
 @return State* currentState state of the player
 */
State* Player::getState() {
	return currentState;
}

/**
 @breif switches current item
 @param bool iterateUp boolean if end of Inventory list or not
 */

void Player::setCurrentToNextItem(bool iterateUp) {
	int itemId = currentState->getCurrentItemSelected();
	std::vector<int> itemsInInventory = currentState->getItems();
	if(!(itemsInInventory.size() <= 1)) {
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
}

/**
 @breif changes direction the players facing
 @param bool iterateUp boolean if end of direction list or not
 */
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

/**
 @breif Add item to invetory
 @param int i where to put the item in inventory list
 @param int itemId what itemId to add to inventory
 */
void Player::addToInventory(int i, int itemId) {
	currentState->setItem(i,itemId);
}
/**
 @breif gets current item selected
 @return int current itemId selected
 */
int Player::getCurrentItem() {
	return currentState->getCurrentItemSelected();
}

/**
 @breif gets current size of invenotry 
 @return int size of intentory list
 */
int Player::getInventorySize(){
	return currentState->getItems().size();
}