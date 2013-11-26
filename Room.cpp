// function template
#include "Room.h"


Room::Room(void) {
}

Room::~Room(void) {
	//?? memoryleeekekekes?
}

void Room::setDescription(int rd, string desc){
	currentRoomState.setDesc(rd, desc);
}
string Room::getDescription(int rd) {
	return currentRoomState.getDesc(rd);
}

void Room::setEvent(Event e) {
	
}
vector<Event> Room::getEvents(int action) {
	vector<Event> ret;
	for(int i =0; i<events.size(); i++) {
		if(events[i].getAction() == action) {
			ret.push_back(events[i]);
		}
	}
	return ret;
}

vector<MyLeapAction> Room::getAllowedActions() {
	vector<MyLeapAction> ret;
	for(int i =0; i<events.size(); i++) {
		ret.push_back(events[i].getAction());
	}
	return ret;
}

void Room::setDoor(int rd, Room* r) {
	currentRoomState.setDoor(rd, r);
}


Room* Room::getDoor(int rd) {
	return currentRoomState.getDoor(rd);
}

void overwrite(){



}

bool isEqual(State s){

}
/*
void Room::tomte() {
  
	string name;
	string hej = "Hallo Elleh!\n";
	string name1 = "What's your name?\n";
	string douche = "!?!? What a silly name!\n\n";
	string silly = name+douche;

	printText(hej);
	printText(name1);
	printText("My name is ");
	getline(cin, name);
	printText(name);
	printText(silly);
	getchar();

}
*/


  

 

  /* some possible cursors */
  /*
20
  for (unsigned i = 176; i < 179; i++)
21
    cout << char(i) << ' ';
22
  cout << endl;
23
 
24
  for (unsigned i = 219; i < 223; i++)
25
    cout << char(i) << ' ';
26
  cout << endl;
27
  */
  
