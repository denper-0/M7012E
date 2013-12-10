#include "State.h"



void State::setItem(int i, int itemId) {
	this->items[i] = itemId;
}
std::vector<int> State::getItems() {
	return this->items;
}
void State::setItemToRemove(int i, int itemId) {
	this->itemsToRemove[i] = itemId;
}
std::vector<int> State::getItemsToRemove() {
	return this->itemsToRemove;
}