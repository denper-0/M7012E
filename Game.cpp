#include "Game.h"


Game::Game(void) {
	generalText = new Gametext("generalText.txt");
	descText = new Gametext("descText.txt");
	itemText = new Gametext("items.txt");
}


Game::~Game(void) {

}

void Game::decorateRoom(Room *r, int option, std::string text) {
	Event* e;
	switch(option) {
	case DECORATE_ROTATE_ROOM_LEFT:
		e = new Event(
			SWIPE_LEFT,
			new PlayerState(), // current State
			new RoomState(),
			new PlayerState(), // new state
			new RoomState(),
			text
		);
		e->setActionOnEvent(ON_EVENT_ITERATE_FACING_LEFT);
		e->setActionOnEvent(ON_EVENT_PRINT_DIRECTION);
		r->setEvent(e);
		break;
	case DECORATE_ROTATE_ROOM_RIGHT:
		e = new Event(
			SWIPE_RIGHT,
			new PlayerState(), // current State
			new RoomState(),
			new PlayerState(), // new state
			new RoomState(),
			text
		);
		e->setActionOnEvent(ON_EVENT_ITERATE_FACING_RIGHT);
		e->setActionOnEvent(ON_EVENT_PRINT_DIRECTION);
		r->setEvent(e);
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

Event* Game::createInventory() {

	// create inventory "room"
	Room* inventory = new Room(0);

	// add close inventory
	Event* e = new Event(SWIPE_DOWN,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"You closed inventory. "
	);
	e->setMoveToNextRoom(true);
	inventory->setEvent(e);
	
	// add iterate up
	e = new Event(
		CIRCLE_CLOCKWISE,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"Current item in hand: "
	);
	e->setActionOnEvent(ON_EVENT_ITERATE_ITEMS_LEFT);
	e->setActionOnEvent(ON_EVENT_PRINT_CURRENT_ITEM);
	inventory->setEvent(e);
	
	// add iterate down
	e = new Event(
		CIRCLE_COUNTER_CLOCKWISE,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"Current item in hand: "
	);
	e->setActionOnEvent(ON_EVENT_ITERATE_ITEMS_RIGHT);
	e->setActionOnEvent(ON_EVENT_PRINT_CURRENT_ITEM);
	inventory->setEvent(e);

	// create event for opening inventory
	Event* InventoryEvent = new Event(
		SWIPE_UP,
		new PlayerState(),
		new RoomState(),
		new PlayerState(),
		new RoomState(),
		"You opened inventory.\nCurrent item in hand: "
	);
	InventoryEvent->setActionOnEvent(ON_EVENT_PRINT_CURRENT_ITEM);
	InventoryEvent->setBarelyEscapable(inventory);
	return InventoryEvent;
}



void Game::initLevel() {
	
	Event* InventoryEvent  = Game::createInventory();
	Event* e;
	RoomState* rs;
	PlayerState* ps;
	
	/**CREATION OF CURRENTROOM**/
	currentPlayer = new Player();
	currentPlayer->addToInventory(0,0);
	


	currentRoom = new Room(1);

	currentRoom->setDescription(0, descText->getText(0));
	currentRoom->setDescription(1, descText->getText(1));
	currentRoom->setDescription(2, descText->getText(2));
	currentRoom->setDescription(3, descText->getText(3));
	
	currentRoom->setEvent(InventoryEvent);
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_LEFT, "You turned left\n");
	decorateRoom(currentRoom, DECORATE_ROTATE_ROOM_RIGHT, "You turned right\n");


	/**CREATION OF SECOND ROOM**/

	Room* room2 = new Room(2);
	room2->setDescription(0, descText->getText(4));
	room2->setDescription(1, descText->getText(5));
	room2->setDescription(2, descText->getText(6));
	room2->setDescription(3, descText->getText(7));
	room2->setDescription(4,generalText->getText(1));
	room2->setEvent(InventoryEvent);
	decorateRoom(room2, DECORATE_ROTATE_ROOM_LEFT, "You turned left. \n");
	decorateRoom(room2, DECORATE_ROTATE_ROOM_RIGHT, "You turned right. \n");
	
	connectRooms(currentRoom, room2, EAST);

	/**CREATION OF THIRD ROOM**/

	Room* room3 = new Room(3);
	room3->setDescription(0, descText->getText(8));
	room3->setDescription(1, descText->getText(9));
	room3->setDescription(2, descText->getText(10));
	room3->setDescription(3, descText->getText(11));
	room3->setDescription(4, generalText->getText(2));
	room3->setEvent(InventoryEvent);
	decorateRoom(room3, DECORATE_ROTATE_ROOM_LEFT, "You turned left. \n");
	decorateRoom(room3, DECORATE_ROTATE_ROOM_RIGHT, "You turned right. \n");
	
	connectRooms(room2, room3, EAST);

	/**CREATION OF FOURTH ROOM**/

	Room* room4 = new Room(4);
	room4->setDescription(0, descText->getText(16));
	room4->setDescription(1, descText->getText(17));
	room4->setDescription(2, descText->getText(18));
	room4->setDescription(3, descText->getText(19));
	room4->setDescription(4,generalText->getText(3));
	room4->setEvent(InventoryEvent);
	decorateRoom(room4, DECORATE_ROTATE_ROOM_LEFT, "You turned left. \n");
	decorateRoom(room4, DECORATE_ROTATE_ROOM_RIGHT, "You turned right.. \n");
	
	connectRooms(room3, room4, NORTH);

	/**CREATION OF FIFTH ROOM**/

	Room* room5 = new Room(5);
	room5->setDescription(0, descText->getText(12));
	room5->setDescription(1, descText->getText(13));
	room5->setDescription(2, descText->getText(14));
	room5->setDescription(3, descText->getText(15));
	room5->setDescription(4, generalText->getText(4));
	room5->setEvent(InventoryEvent);
	decorateRoom(room5, DECORATE_ROTATE_ROOM_LEFT, "You turned left. \n");
	decorateRoom(room5, DECORATE_ROTATE_ROOM_RIGHT, "You turned right. \n");
	
	room5->setItem(0,1);
	rs = new RoomState();
	RoomState* rs2 = new RoomState();
	rs->setItem(0, 1);
	//rs2->getItemsToRemove();
	rs2->setDesc(NORTH, "no key here anymore. ");
	ps = new PlayerState();
	ps->setItem(0,1);
	e = new Event(
		SWIPE_DOWN,
		new PlayerState(NORTH),
		rs,
		ps,
		rs2,
		"You picked up "+itemText->getText(1)
	);
	room5->setEvent(e);

	connectRooms(room3, room5, EAST);

	Room *goal = new Room(6);
	goal->setEvent(new Event(
		NOTHING,
		new PlayerState(), // current state
		new RoomState(),
		new PlayerState(), // new state
		new RoomState(),
		"You won the game. "
	));
	setEventOnDoor(currentRoom, SOUTH, "You walks though the toiletdoor!");
	currentRoom->setDoor(SOUTH, goal); // no way back ^^
	goal->setRoomIsLocked(true);

	
	rs = new RoomState();
	rs->setRoomIsLocked(NEXT_ROOM_IS_LOCKED);
	e = new Event(
		SWIPE_FORWARD,
		new PlayerState(SOUTH),
		rs,
		new PlayerState(),
		new RoomState(),
		descText->getText(20)
	);
	currentRoom->setEvent(e);

	rs = new RoomState();
	rs->setRoomIsLocked(NEXT_ROOM_IS_LOCKED);
	ps = new PlayerState(SOUTH);
	ps->setCurrentItemSelected(1);
	rs2 = new RoomState();
	rs2->setRoomIsLocked(NEXT_ROOM_IS_UNLOCKED);
	rs2->setDesc(SOUTH, "OMG door is unlockededded!");
	e = new Event(
		SWIPE_FORWARD,
		ps,
		rs,
		new PlayerState(),
		rs2,
		"You used the key! Door is unlocked!"
	);
	currentRoom->setEvent(e);
}

void Game::printText(std::string str){
	str = str+"\n";
	//cout << string(50, '\n');
	for (unsigned i = 0; i < str.length(); i++)
  {
    std::cout << str[i];
    if((i + 1) < str.length() && str[i+1] != '\n')
      std::cout << char(219);
    Sleep(40);
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
	this->printText(generalText->getText(0));
	//generalText->getText(currentRoom->getDescription(NO_DIRECTION)); LOOL
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
	std::vector<OnEventAction> eventActions;
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
		if(currentPlayer->isEqual(events[i]->getCurrentPlayerstate(), new State()) 
			&& currentRoom->isEqual(events[i]->getCurrentRoomstate(), events[i]->getCurrentPlayerstate())) {
			
		} else {
			events.erase(events.begin()+i);
			i--;
		}
	}

	// trigger the events. 
	for(size_t i=0; i < events.size(); i++) {

		nextRoom = currentRoom->getDoor(currentPlayer->getFacing());

		// The actions
		currentPlayer->overWrite((events[i]->getNewPlayerstate()), new State());
		currentRoom->overWrite((events[i]->getNewRoomstate()), currentPlayer->getState());
		
		output = events[i]->getText();

		eventActions = events[i]->getActionOnEvent();
		for(size_t j=0; j < eventActions.size(); j++) {
			switch (eventActions[j]) {
			case ON_EVENT_NO_ACTION:
				break;
			case ON_EVENT_ITERATE_ITEMS_LEFT:
				currentPlayer->setCurrentToNextItem(false);
				break;
			case ON_EVENT_ITERATE_ITEMS_RIGHT:
				currentPlayer->setCurrentToNextItem(true);
				break;
			case ON_EVENT_PRINT_CURRENT_ITEM:
				output += itemText->getText(currentPlayer->getCurrentItem());
				break;
			case ON_EVENT_ITERATE_FACING_LEFT:
				currentPlayer->setCurrentToNextDirection(false);
				break;
			case ON_EVENT_ITERATE_FACING_RIGHT:
				currentPlayer->setCurrentToNextDirection(true);
				break;
			case ON_EVENT_PRINT_DIRECTION:
				output += currentRoom->getDescription(currentPlayer->getFacing());
				break;
			default:

				break;
			}
		}
		

		// print the events output. 
		if(output.empty() == false && events[i]->getMoveToNextRoom() == false) {
			this->printText(output);
		}

		// change room if event is ment to do that. 
		if(events[i]->getMoveToNextRoom()) {
			
			if(nextRoom != NULL) {
				
				if(nextRoom->getRoomIsLocked() != NEXT_ROOM_IS_LOCKED) {
					this->printText(output);

					currentRoom = nextRoom;

					// print next rooms description. 
					this->printText(currentRoom->getDescription(NO_DIRECTION)); // print general description
					this->printText(currentRoom->getDescription(currentPlayer->getFacing())); // print facing description

					// break loop, no event carry over plz!
					i=events.size();
				}
			} else {
				this->printText(output);
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