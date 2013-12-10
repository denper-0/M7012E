#include "State.h"


void State::setItem(int i, int itemId) {
	if(items.size() <= i) {
		items.push_back(itemId);
		return;
	}
	this->items.at(i) = itemId;
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