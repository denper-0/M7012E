// function template
#include "Room.h"


Room::Room(int roomId) {
	currentRoomState = new RoomState();
	this->roomId = roomId;
}

Room::~Room(void) {
	//?? memoryleeekekekes?
}

/**
 @breif returns a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @param string desc the description
 */
void Room::setDescription(int rd, std::string desc){
	currentRoomState->setDesc(rd, desc);
}

/**
 @breif returns a description
 @param int dir is the direction facing in the room 
 @return 
 */
std::string Room::getDescription(int rd) {
	return currentRoomState->getDesc(rd);
}

/**
 @breif add event to the event vector
 @param Event* e the event to be added 
 */
void Room::setEvent(Event* e) {
	events.push_back(e);
}

/**
 @breif returns event on action
 @param int action an action that occured
 @return vector<Event*> returns vector with event connected to action
 */
std::vector<Event*> Room::getEvents(int action) {
	std::vector<Event*> ret;
	for(size_t i =0; i < events.size(); i++) {
		if(events[i]->getAction() == action) {
			ret.push_back(events[i]);
		}
	}
	return ret;
}

/**
 @breif returns what action the room's event's react too 
 @return vector<MyLeapAction> vector with allowed action for the event in a room
 */
std::vector<MyLeapAction> Room::getAllowedActions() {
	std::vector<MyLeapAction> ret;
	for(size_t i =0; i<events.size(); i++) {
		ret.push_back(events[i]->getAction());
	}
	return ret;
}

/**
 @breif adds door
 @param int rd direction in the room
 @param Room* r the room that the door is going to lead to
 */
void Room::setDoor(int rd, Room* r) {
	currentRoomState->setDoor(rd, r);
}

/**
 @breif returns the room the door is connected to
 @param int dir is the direction facing in the room 
 @return Room* room the door is connected too 
 */
Room* Room::getDoor(int rd) {
	return currentRoomState->getDoor(rd);
}

/**
 @breif adds item to room
 @param int dir is the direction facing in the room 
 */

void Room::setItem(int i, int itemId) {
	currentRoomState->setItem(i, itemId);
}

/**
 @breif returns the current state for the room
 @return State* current stat for the room
 */
State* Room::getState() {
	return currentRoomState;
}

/**
 @breif overwrites this room's state with given roomstate, NULL IGNORES
 @param State* s roomstate to overwrite with
 @param State* s2 the Playerstate to know facing 
 */
void Room::overWrite(State* s, State* s2) {
	RoomState* rs = static_cast<RoomState*>(s); // typecast
	PlayerState* playerState = static_cast<PlayerState*>(s2); // typecast

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
	for(size_t i =0; i < currentRoomState->getItems().size(); i++) {
		if(rs->getItem(i) != NULL) {
			setItem(i, rs->getItem(i));
		}
	}
	if(rs->getRoomIsLocked() != NEXT_ROOM_IS_NULL ) {
		Room* nextRoom = currentRoomState->getDoor(playerState->getFacing());
		if(nextRoom != NULL) {
			nextRoom->setRoomIsLocked(rs->getRoomIsLocked());
		}
	}
}

/**
 @breif checks if this room's state is equal to the given roomstate
 @param State* s roomstate to compare with
 @param State* s2 the Playerstate to know facing 
 @return boolean if equal true ELSE false
 */
bool Room::isEqual(State* s, State* s2) {
	RoomState* rs = static_cast<RoomState*>(s); // typecast
	PlayerState* currentPlayer = static_cast<PlayerState*>(s2); // typecast
	
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

	int facing = currentPlayer->getFacing();
	if(facing != NULL) {
		Room* nextRoom = currentRoomState->getDoor(facing);
		if(nextRoom != NULL && rs->getRoomIsLocked() != NEXT_ROOM_IS_NULL 
				&& nextRoom->getRoomIsLocked() != rs->getRoomIsLocked()) {
			return false;
		}
	}

	return true;
}

/**
 @breif returns roomId
 @return int the rooms id 
 */
int Room::getRoomId() {
	return roomId;
}
  
/**
 @breif overwrites this room's state with given roomstate, NULL IGNORES
 @param State* s roomstate to overwrite with
 @param State* s2 the Playerstate to know facing 
 */
int Room::getRoomIsLocked() {
	return currentRoomState->getRoomIsLocked();
}
void Room::setRoomIsLocked(int locked) {
	currentRoomState->setRoomIsLocked(locked);
}