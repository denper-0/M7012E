#pragma once
#include <vector>

// abstract class ment for a state that can be fetched to StateHolder. 
class State
{
protected:
	std::vector<int> items;
	std::vector<int> itemsToRemove;
public:
	void setItem(int i, int itemId);
	std::vector<int> getItems();
	void setItemToRemove(int i, int itemId);
	std::vector<int> getItemsToRemove();

};