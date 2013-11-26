#include "Main.h"

using namespace std;

Main::Main(void) {

}

Main::~Main(void) {

}

/*
first prototype
int Main::printText(string str){
	str = str+"\n";
	//cout << string(50, '\n');
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
	
	Player *player = new Player();
	Room *currentRoom = new Room();

	currentRoom->setDescription(NORTH, "You are facing north. ");
	currentRoom->setDescription(WEST, "You are facing west. ");
	//currentRoom->onAction(ROTATE_LEFT, new PlayerState(NORTH), "You turned left, "+currentRoom->getDescription(WEST));


	vector<Event> currentEvents;
	while(true) {
		currentEvents = currentRoom->getEvents();


		action = L->getAction(0,actions);

		if(action != NOTHING) {
			
			if(action == ROTATE_LEFT) {
				if(player->getFacing() == NORTH) {
					player->setFacing(WEST);
				} else {
					player->setFacing(player->getFacing()-1);
				}
				printText(currentRoom->getDescription(player->getFacing()));
			} else if(action == ROTATE_RIGHT) {
				if(player->getFacing() == WEST) {
					player->setFacing(NORTH);
				} else {
					player->setFacing(player->getFacing()+1);
				}
				printText(currentRoom->getDescription(player->getFacing()));
			}
		}

	}
}
*/
int main(void)
{
	Game g;
	g.initLevel();
	return g.looper();
}


