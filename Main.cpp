#include "Main.h"
#include "MyLeap.h"
#include "Room.h"
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;



int main(void)
{
	MyLeap* L;
	L = new MyLeap();
	std::vector<MyLeapAction> actions;
	actions.push_back(ROTATE_LEFT);
	actions.push_back(ROTATE_RIGHT);
	MyLeapAction action;
	while(true) {
		action = L->getAction(0,actions);
		if(action != NOTHING) {
			std::cout << "Action: " << action << std::endl;
		}
	}
	return 0;
	
		

}


