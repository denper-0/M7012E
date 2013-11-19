#include "Main.h"
#include "MyLeap.h"
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

Main::Main(void) {

}

Main::~Main(void) {

}

int Main::printText(string str){

	for (unsigned i = 0; i < str.length(); i++)
  {
    cout << str[i];
    if((i + 1) < str.length() && str[i+1] != '\n')
      cout << char(219);
    Sleep(50);
    if((i + 1) < str.length() && str[i+1] != '\n')
      cout << char(8);
  }
  cout << ' ' << char(8); 
  return(0);

}

void Main::looper() {
	
	MyLeap* L;
	L = new MyLeap();
	std::vector<MyLeapAction> actions;
	actions.push_back(ROTATE_LEFT);
	actions.push_back(ROTATE_RIGHT);
	MyLeapAction action;
	while(true) {
		action = L->getAction(0,actions);
		if(action != NOTHING) {
			if(action == ROTATE_LEFT) {
				printText("Left\n");
			} else {
				printText("Right\n");
			}
		}
	}
}

int main(void)
{
	Main m;
	m.looper();
	return 0;
}


