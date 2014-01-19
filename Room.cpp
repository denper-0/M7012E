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


State* Room::getState() {
	return currentRoomState;
}


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


int Room::getRoomId() {
	return roomId;
}
  

int Room::getRoomIsLocked() {
	return currentRoomState->getRoomIsLocked();
}
void Room::setRoomIsLocked(int locked) {
	currentRoomState->setRoomIsLocked(locked);
}