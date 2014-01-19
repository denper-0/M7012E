#include "Event.h"



Event::Event(MyLeapAction a, PlayerState* current_PS, RoomState* current_RS, PlayerState* newPS, RoomState* newRS, std::string eText) {
	action = a;
	cur_PS = current_PS;
	new_PS = newPS;
	cur_RS = current_RS;
	new_RS = newRS;
	eventText = eText;
	moveToNextRoom = false;
	barelyEscapable = false;
	Room* barelyEscapableRoom = NULL;
}


Event::~Event(void) {

}

void Event::setText(std::string eventStr){
	eventText = eventStr;
}


std::string Event::getText(){
	 return eventText;
}

void Event::setPlayerState(PlayerState* currentPS, PlayerState* newPS){
	cur_PS = currentPS;
	new_PS = newPS;
}


void Event::setRoomState(RoomState* currentRS,RoomState* newRS){
	cur_RS = currentRS;
	new_RS = newRS;
}

PlayerState* Event::getNewPlayerstate() {
	return new_PS;
}

RoomState* Event::getNewRoomstate() {
	return new_RS;
}

PlayerState* Event::getCurrentPlayerstate() {
	return cur_PS;
}

RoomState* Event::getCurrentRoomstate() {
	return cur_RS;
}

MyLeapAction Event::getAction() {
	return action;
}

bool Event::getMoveToNextRoom() {
	return moveToNextRoom;
}

void Event::setMoveToNextRoom(bool isOnThisEvent) {
	moveToNextRoom = isOnThisEvent;
}

bool Event::isBarelyEscapable() {
	return barelyEscapable;
}

void Event::setBarelyEscapable(Room *barelyEscapableRoom) {
	this->barelyEscapableRoom = barelyEscapableRoom;
	if(barelyEscapableRoom != NULL) {
		barelyEscapable = true;
	} else{
		barelyEscapable = false;
	}
}

Room* Event::getBarelyEscapableRoom() {
	return barelyEscapableRoom;
}

void Event::setActionOnEvent(OnEventAction action) {
	this->eventActions.push_back(action);
}


std::vector<OnEventAction> Event::getActionOnEvent() {
	return this->eventActions;
}
