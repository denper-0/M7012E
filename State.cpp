#include "State.h"


void State::setItem(int i, int itemId) {
	if(items.size() <= i) {
		items.resize(i+1,NULL);
	}
	this->items.at(i) = itemId;
}
std::vector<int> State::getItems() {
	return this->items;
}
int State::getItem(int i) {
	if(items.size() <= i) {
		return NULL;
	}
	return this->items.at(i);
}
void State::setItemToRemove(int i, int itemId) {
	if(itemsToRemove.size() <= i) {
		itemsToRemove.push_back(itemId);
	}
	this->itemsToRemove[i] = itemId;
}
std::vector<int> State::getItemsToRemove() {
	return this->itemsToRemove;
}