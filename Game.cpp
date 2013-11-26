#include "Game.h"


Game::Game(void) {
	text = new Gametext();
	currentRoom = new Room();
}


Game::~Game(void) {

}

Room Game::decorateRoom(Room *r, int option, string text) {
	switch(option) {
	case DECORATE_ROTATE_ROOM_LEFT:
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(NORTH), // current State
			*new RoomState(),
			*new PlayerState(WEST), // new state
			*new RoomState(),
			text+r->getDescription(WEST)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(WEST), // current State
			*new RoomState(),
			*new PlayerState(SOUTH), // new state
			*new RoomState(),
			text+r->getDescription(SOUTH)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(SOUTH), // current State
			*new RoomState(),
			*new PlayerState(EAST), // new state
			*new RoomState(),
			text+r->getDescription(EAST)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(EAST), // current State
			*new RoomState(),
			*new PlayerState(NORTH), // new state
			*new RoomState(),
			text+r->getDescription(NORTH)
		));

		break;
	case DECORATE_ROTATE_ROOM_RIGHT:
		r->setEvent(*new Event(
			ROTATE_RIGHT,
			*new PlayerState(NORTH), // current state
			*new RoomState(),
			*new PlayerState(EAST), // new state
			*new RoomState(),
			text+r->getDescription(EAST)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(EAST), // current state
			*new RoomState(),
			*new PlayerState(SOUTH), // new state
			*new RoomState(),
			text+r->getDescription(SOUTH)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(SOUTH), // current state
			*new RoomState(),
			*new PlayerState(WEST), // new state
			*new RoomState(),
			text+r->getDescription(WEST)
		));
		r->setEvent(*new Event(
			ROTATE_LEFT,
			*new PlayerState(WEST), // current state
			*new RoomState(),
			*new PlayerState(NORTH), // new state
			*new RoomState(),
			text+r->getDescription(NORTH)
		));
		break;
	default: 
		break;
	}
}

void Game::connectRooms(Room *r1, Room *r2, int firstRoomsDirection) {
	if(firstRoomsDirection == NORTH) {
		r1->setDoor(NORTH, r1);
		r2->setDoor(SOUTH, r2);
	} else if(firstRoomsDirection == EAST) {
		r1->setDoor(EAST, r1);
		r2->setDoor(WEST, r2);
	} else if(firstRoomsDirection == SOUTH) {
		r1->setDoor(SOUTH, r1);
		r2->setDoor(NORTH, r2);
	} else if(firstRoomsDirection == WEST) {
		r1->setDoor(WEST, r1);
		r2->setDoor(EAST, r2);
	}
}

void Game::initLevel() {
	
	currentRoom->setEvent(*new Event(
		NOTHING,
		*new PlayerState(), // current state
		*new RoomState(),
		*new PlayerState(), // new state
		*new RoomState(),
		text->getText(0)
	));

	currentRoom->setDescription(0, text->getText(1));
	currentRoom->setDescription(1, text->getText(2));
	currentRoom->setDescription(2, text->getText(3));
	currentRoom->setDescription(3, text->getText(4));
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_LEFT, text->getText(9));
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_RIGHT, text->getText(10));

	Room *room2 = new Room();
	currentRoom->setDescription(0, text->getText(5));
	currentRoom->setDescription(1, text->getText(6));
	currentRoom->setDescription(2, text->getText(7));
	currentRoom->setDescription(3, text->getText(8));
	decorateRoom(room2, DECORATE_ROTATE_ROOM_LEFT, text->getText(9));
	decorateRoom(room2, DECORATE_ROTATE_ROOM_RIGHT, text->getText(10));

	Room *goal = new Room();
	goal->setEvent(*new Event(
		NOTHING,
		*new PlayerState(), // current state
		*new RoomState(),
		*new PlayerState(), // new state
		*new RoomState(),
		text->getText(100)
	));

	connectRooms(currentRoom, room2, NORTH);

	room2->setDoor(NORTH, goal); // no way back ^^
}

void Game::printText(string str){
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
}

int Game::looper() {
	MyLeapAction a;
	vector<MyLeapAction> allowedActions;
	
	Room* nextRoom;

	MyLeap* L;
	L = new MyLeap();
	vector<Event> events;
	vector<Event> eventsOnNothingAction;
	string output;

	while (true) {
		allowedActions = currentRoom->getAllowedActions();
		a = L->getAction(0, allowedActions);
		
		eventsOnNothingAction = currentRoom->getEvents(NOTHING);
		events = currentRoom->getEvents(a);
		events.insert( events.end(), eventsOnNothingAction.begin(), eventsOnNothingAction.end() );
		
		for(int i=0; i<events.size(); i++) {
			if(currentPlayer->isEqual(events[i].getCurrentPlayerstate()) && currentRoom->isEqual(events[i].getCurrentRoomstate()) {
				currentPlayer->overWrite((events[i]->getNewPlayerstate());
				currentRoom->overWrite((events[i]->getNewRoomstate());
				output = events[i]->getText();
				if(output) {
					this->printText(output);
				}
				if(events[i]->getMoveToNextRoom()) {
					nextRoom = currentRoom->getRoom(currentPlayer->getFacing());
					if(nextRoom) {
						currentRoom = nextRoom;
						// print description here?
						this->printText();
					}
				}
			}
		}
	}
	return 0;
}