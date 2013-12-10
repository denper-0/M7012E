#include "Game.h"


Game::Game(void) {
	text = new Gametext();
}


Game::~Game(void) {

}

void Game::decorateRoom(Room *r, int option, std::string text) {
	switch(option) {
	case DECORATE_ROTATE_ROOM_LEFT:
		r->setEvent(new Event(
			SWIPE_LEFT,
			new PlayerState(NORTH), // current State
			new RoomState(),
			new PlayerState(WEST), // new state
			new RoomState(),
			text+r->getDescription(WEST)
		));
		r->setEvent(new Event(
			SWIPE_LEFT,
			new PlayerState(WEST), // current State
			new RoomState(),
			new PlayerState(SOUTH), // new state
			new RoomState(),
			text+r->getDescription(SOUTH)
		));
		r->setEvent(new Event(
			SWIPE_LEFT,
			new PlayerState(SOUTH), // current State
			new RoomState(),
			new PlayerState(EAST), // new state
			new RoomState(),
			text+r->getDescription(EAST)
		));
		r->setEvent(new Event(
			SWIPE_LEFT,
			new PlayerState(EAST), // current State
			new RoomState(),
			new PlayerState(NORTH), // new state
			new RoomState(),
			text+r->getDescription(NORTH)
		));

		break;
	case DECORATE_ROTATE_ROOM_RIGHT:
		r->setEvent(new Event(
			SWIPE_RIGHT,
			new PlayerState(NORTH), // current state
			new RoomState(),
			new PlayerState(EAST), // new state
			new RoomState(),
			text+r->getDescription(EAST)
		));
		r->setEvent(new Event(
			SWIPE_RIGHT,
			new PlayerState(EAST), // current state
			new RoomState(),
			new PlayerState(SOUTH), // new state
			new RoomState(),
			text+r->getDescription(SOUTH)
		));
		r->setEvent(new Event(
			SWIPE_RIGHT,
			new PlayerState(SOUTH), // current state
			new RoomState(),
			new PlayerState(WEST), // new state
			new RoomState(),
			text+r->getDescription(WEST)
		));
		r->setEvent(new Event(
			SWIPE_RIGHT,
			new PlayerState(WEST), // current state
			new RoomState(),
			new PlayerState(NORTH), // new state
			new RoomState(),
			text+r->getDescription(NORTH)
		));
		break;
	default: 
		break;
	}
}

void Game::setEventOnDoor(Room* r, int direction, std::string output) {
	Event* e;
	e = new Event(
		SWIPE_FORWARD,
		new PlayerState(direction), // current state
		new RoomState(),
		new PlayerState(), // new state
		new RoomState(),
		output
	);
	e->setMoveToNextRoom(true);
	r->setEvent(e);
}
void Game::connectRooms(Room *r1, Room *r2, int firstRoomsDirection) {
	if(firstRoomsDirection == NORTH) {
		setEventOnDoor(r1, NORTH, "");
		setEventOnDoor(r2, SOUTH, "");
		r1->setDoor(NORTH, r2);
		r2->setDoor(SOUTH, r1);
	} else if(firstRoomsDirection == EAST) {
		setEventOnDoor(r1, EAST, "");
		setEventOnDoor(r2, WEST, "");
		r1->setDoor(EAST, r2);
		r2->setDoor(WEST, r1);
	} else if(firstRoomsDirection == SOUTH) {
		setEventOnDoor(r1, SOUTH, "");
		setEventOnDoor(r2, NORTH, "");
		r1->setDoor(SOUTH, r2);
		r2->setDoor(NORTH, r1);
	} else if(firstRoomsDirection == WEST) {
		setEventOnDoor(r1, WEST, "");
		setEventOnDoor(r2, EAST, "");
		r1->setDoor(WEST, r2);
		r2->setDoor(EAST, r1);
	}
}

void Game::initLevel() {
	currentPlayer = new Player();

	currentRoom = new Room(1);

	currentRoom->setDescription(0, text->getText(1));
	currentRoom->setDescription(1, text->getText(2));
	currentRoom->setDescription(2, text->getText(3));
	currentRoom->setDescription(3, text->getText(4));
	currentRoom->setDescription(4, text->getText(5));
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_LEFT, "You turned left\n");
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_RIGHT, "You turned right\n");

	Event* InventoryEvent = new Event(SWIPE_UP,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"You opened inventory. "
	);
	Room* inventory = new Room(2);
	InventoryEvent->setBarelyEscapable(inventory);
	currentRoom->setEvent(InventoryEvent);

	Event* e = new Event(SWIPE_DOWN,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"You closed inventory. "
	);
	e->setMoveToNextRoom(true);
	inventory->setEvent(e);
	inventory->setEvent(new Event(
		SWIPE_LEFT,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"You opened inventory. "
	));

	Room* room2 = new Room(3);
	room2->setDescription(0, "NORTH, room2");
	room2->setDescription(1, "EAST, room2");
	room2->setDescription(2, "SOUTH, room2");
	room2->setDescription(3, "WEST, room2");
	room2->setEvent(InventoryEvent);
	decorateRoom(room2, DECORATE_ROTATE_ROOM_LEFT, "You rotated the wall. \n");
	decorateRoom(room2, DECORATE_ROTATE_ROOM_RIGHT, "You rotated the wall. \n");
	
	connectRooms(currentRoom, room2, SOUTH);

	Room *goal = new Room(4);
	goal->setEvent(new Event(
		NOTHING,
		new PlayerState(), // current state
		new RoomState(),
		new PlayerState(), // new state
		new RoomState(),
		"You won the game. "
	));
	setEventOnDoor(room2, NORTH, "You can see the goal, and runs like hell towards the light!");


	room2->setDoor(NORTH, goal); // no way back ^^
}

void Game::printText(std::string str){
	str = str+"\n";
	//cout << string(50, '\n');
	for (unsigned i = 0; i < str.length(); i++)
  {
    std::cout << str[i];
    if((i + 1) < str.length() && str[i+1] != '\n')
      std::cout << char(219);
    Sleep(20);
    if((i + 1) < str.length() && str[i+1] != '\n')
      std::cout << char(8);
  }
  std::cout << ' ' << char(8); 
}

int Game::looper() {
	MyLeapAction a;
	Room* nextRoom;
	L = new MyLeap();
	std::vector<Event*> events;
	std::vector<Event*> eventsOnNothingAction;
	std::string output;
	std::vector<MyLeapAction> actions;



	Room* barelyEscapableRoom;
	bool hasEscaped = false;
	// first message
	this->printText(text->getText(0));

	nextRoom = currentRoom;
	while(true) {
		if(currentRoom != NULL) {
			nextRoom = currentRoom;
			currentRoom = runLoopOnRoom(currentRoom);
		} else {
			currentRoom = nextRoom;
		}
	}
}

Room* Game::runLoopOnRoom(Room *currentRoom) {
	MyLeapAction a;
	Room* nextRoom;
	std::vector<Event*> events;
	std::vector<Event*> eventsOnNothingAction;
	std::string output;
	
	std::vector<MyLeapAction> actions;

	Room* barelyEscapableRoom;
	bool hasEscaped = false;

	// get input from user
	actions = currentRoom->getAllowedActions();
	a = L->getAction(0, actions);
		
	// add events that will trigger regardless of input. 
	if(a != NOTHING) {
		eventsOnNothingAction = currentRoom->getEvents(NOTHING);
		events = currentRoom->getEvents(a);
		events.insert( events.end(), eventsOnNothingAction.begin(), eventsOnNothingAction.end() );
	} else {
		events = currentRoom->getEvents(a);
	}

	// remove events that are not ment to be triggered regard to the states. 
	for(size_t i=0; i < events.size(); i++) {
		if(currentPlayer->isEqual(events[i]->getCurrentPlayerstate()) && currentRoom->isEqual(events[i]->getCurrentRoomstate())) {
				
		} else {
			events.erase(events.begin()+i);
			i--;
		}
	}

	// trigger the events. 
	for(size_t i=0; i < events.size(); i++) {

		// The actions
		currentPlayer->overWrite((events[i]->getNewPlayerstate()));
		currentRoom->overWrite((events[i]->getNewRoomstate()));
		output = events[i]->getText();

		// print the events output. 
		if(output.empty() == false) {
			this->printText(output);
		}

		// change room if event is ment to do that. 
		if(events[i]->getMoveToNextRoom()) {
			nextRoom = currentRoom->getDoor(currentPlayer->getFacing());
			if(nextRoom != NULL) {
				currentRoom = nextRoom;

				// print next rooms description. 
				this->printText(currentRoom->getDescription(NO_DIRECTION)); // print general description
				this->printText(currentRoom->getDescription(currentPlayer->getFacing())); // print facing description

				// break loop, no event carry over plz!
				i=events.size();
			} else {
				return NULL;
			}
		} else if(events[i]->isBarelyEscapable()) {
			barelyEscapableRoom = events[i]->getBarelyEscapableRoom();
			hasEscaped = false;
			while(hasEscaped == false) {
				//this->printText("LOL TRY TO ESCAPE!");

				barelyEscapableRoom = this->runLoopOnRoom(barelyEscapableRoom);

				if(barelyEscapableRoom == NULL) {
					return currentRoom;
				}

				if(barelyEscapableRoom->getRoomId() == currentRoom->getRoomId()) {
					return currentRoom;
				}
			}
		}
	}
	return currentRoom;
}