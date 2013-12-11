// function template
#include "Room.h"


Room::Room(int roomId) {
	currentRoomState = new RoomState();
	this->roomId = roomId;
}

Room::~Room(void) {
	//?? memoryleeekekekes?
}

void Room::setDescription(int rd, std::string desc){
	currentRoomState->setDesc(rd, desc);
}
std::string Room::getDescription(int rd) {
	return currentRoomState->getDesc(rd);
}

void Room::setEvent(Event* e) {
	events.push_back(e);
}
std::vector<Event*> Room::getEvents(int action) {
	std::vector<Event*> ret;
	for(size_t i =0; i < events.size(); i++) {
		if(events[i]->getAction() == action) {
			ret.push_back(events[i]);
		}
	}
	return ret;
}

std::vector<MyLeapAction> Room::getAllowedActions() {
	std::vector<MyLeapAction> ret;
	for(size_t i =0; i<events.size(); i++) {
		ret.push_back(events[i]->getAction());
	}
	return ret;
}

void Room::setDoor(int rd, Room* r) {
	currentRoomState->setDoor(rd, r);
}

Room* Room::getDoor(int rd) {
	return currentRoomState->getDoor(rd);
}

void Room::setItem(int i, int itemId) {
	currentRoomState->setItem(i, itemId);
}


void Room::overWrite(State* s) {
	RoomState* rs = static_cast<RoomState*>(s); // typecast

	for(size_t i =0; i < 4; i++) {
		if(rs->getDoor(i) != NULL) {
			this->setDoor(i, rs->getDoor(i));
		}
	}
	for(size_t i =0; i < 4; i++) {
		if(rs->getDesc(i) != "") {
			this->setDescription(i, rs->getDesc(i));
		}
	}
}
bool Room::isEqual(State* s) {
	RoomState* rs = static_cast<RoomState*>(s); // typecast
	
	for(size_t i =0; i < 4; i++) {
		if(rs->getDoor(i) != NULL && rs->getDoor(i) != this->getDoor(i)) {
			return false;
		}
	}
	for(size_t i =0; i < 4; i++) {
		if(rs->getDesc(i) != "" && rs->getDesc(i) != this->getDescription(i)) {
			return false;
		}
	}
	for(size_t i =0; i < currentRoomState->getItems().size(); i++) {
		if(rs->getItem(i) != NULL && rs->getItem(i) != this->currentRoomState->getItem(i)) {
			return false;
		}
	}
	return true;
}

int Room::getRoomId() {
	return roomId;
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
  
