// function template
#include "Room.h"


Room::Room(void) {
	description.resize(4);
	setDescription(0,"You are facing north");
	setDescription(1,"You are facing east");
	setDescription(2,"You are facing south");
	setDescription(3,"You are facing west");
}

Room::~Room(void) {
	//?? memoryleeekekekes?
}

void Room::setDescription(int rd, string desc){
	description[rd] = desc;
}
string Room::getDescription(int rd) {
	return description[rd];
}

void Room::setEvent(Event e) {
	
}
vector<Event> Room::getEvents(MyLeapAction action) {
	vector<Event> ret;
	for(int i =0; i<events.size(); i++) {
		if(events[i].getAction() == action) {
			ret.push_back(events[i]);
		}
	}
	return ret;
}


void Room::setDoor(int rd, Room r) {
	doors[rd] = r;
}
Room Room::getDoor(int rd) {
	return doors[rd];
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
  
