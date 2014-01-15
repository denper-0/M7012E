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
/**
 @breif set text/desciptrition on event
 @param string eventStr text for the event
 */
void Event::setText(std::string eventStr){
	eventText = eventStr;
}

/**
 @breif returns text for event/description
 @return string event text
 */
std::string Event::getText(){
	 return eventText;
}
/**
 @breif sets on what playerstate event skould happend
 @param Playerstate* currentPS the current player state
 @param Playerstate* newPS the new playerstate
 */
void Event::setPlayerState(PlayerState* currentPS, PlayerState* newPS){
	cur_PS = currentPS;
	new_PS = newPS;
}

/**
 @breif sets on what roomstate event skould happend(current) and how that state look afterwards
 @param Roomstate* currentRS the current player state
 @param Roomstate* newRS the new playerstate
 */
void Event::setRoomState(RoomState* currentRS,RoomState* newRS){
	cur_RS = currentRS;
	new_RS = newRS;
}
/**
 @breif returns the new playerstate
 @return Playerstate* new_PS variable
 */
PlayerState* Event::getNewPlayerstate() {
	return new_PS;
}
/**
 @breif returns the new Roomstate
 @return Roomstate* new_RS variable
 */
RoomState* Event::getNewRoomstate() {
	return new_RS;
}
/**
 @breif returns the current playerstate
 @return Playerstate* current_PS variable
 */
PlayerState* Event::getCurrentPlayerstate() {
	return cur_PS;
}
/**
 @breif returns the current Roomstate
 @return Roomstate* current_RS variable
 */
RoomState* Event::getCurrentRoomstate() {
	return cur_RS;
}
/**
 @breif returns the action that the event triggers on
 @return MyLeapAction action
 */
MyLeapAction Event::getAction() {
	return action;
}
/**
 @breif if you are able to move to next room
 @return bool 
 */
bool Event::getMoveToNextRoom() {
	return moveToNextRoom;
}
/**
 @breif set if can move to next room
 @param bool isOnThisEvent 
 */
void Event::setMoveToNextRoom(bool isOnThisEvent) {
	moveToNextRoom = isOnThisEvent;
}
/**
 @breif returns true if barelyEscapable ELSE false
 @return bool
 */
bool Event::isBarelyEscapable() {
	return barelyEscapable;
}
/**
 @breif sets if the event is an barelyEscapable(like the Inventory)
 */
void Event::setBarelyEscapable(Room *barelyEscapableRoom) {
	this->barelyEscapableRoom = barelyEscapableRoom;
	if(barelyEscapableRoom != NULL) {
		barelyEscapable = true;
	} else{
		barelyEscapable = false;
	}
}

/**
 @breif returns barelyEscapableRoom variable
 @return Room*
 */
Room* Event::getBarelyEscapableRoom() {
	return barelyEscapableRoom;
}
/**
 @breif adds that the event triggers on an action
 @param OnEventAction action is action to be added to event
 */
void Event::setActionOnEvent(OnEventAction action) {
	this->eventActions.push_back(action);
}

/**
 @breif returns the vector of actions the event triggers on
 @return vector<OnEventAction>
 */
std::vector<OnEventAction> Event::getActionOnEvent() {
	return this->eventActions;
}