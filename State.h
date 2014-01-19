#pragma once
#include <vector>

/**
 * @breif abstract class ment for a state that can be fetched to StateHolder for easy comperison and overwrites. 
 */
class State
{
protected:
	std::vector<int> items;
	std::vector<int> itemsToRemove;
public:
	/**
 @breif sets an item in a state
 @param int i where in list to add it
 @param int itemId which item to set
 */
	void setItem(int i, int itemId);
	std::vector<int> getItems();
/**
 @breif retuns a vector of items from the state
 @return vector<int> items contains items in state
 */
	int getItem(int);
/**
 @breif removes an item from a state
 @param int i adds item to i index in remove vector from state
 @param int itemId which item to remove from state 
 */
	void setItemToRemove(int i, int itemId);
/**
 @breif retuns remove removeItem vector from a state
 @return vector<int> itemsToRemove contains item that should be removed from state
 */
	std::vector<int> getItemsToRemove();

};
