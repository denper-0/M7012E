#include "Event.h"


/**
 @breif constructs a event with some properties set, rest are set to deafult meaning no change if it fires
 @param MyLeapAction* on what action the event fires
 @param PlayerState* current player state the game loop overwrites with
 @param RoomState* current room state the game loop verifies with
 @param PlayerState* new room state the game loop overwrites with
 @param RoomState* new room state the game loop overwrites with
 @param string eventStr text for the event
 */
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

/**
 * @breif destructor
 */
Event::~Event(void) {

}
/**
 @breif set text/desciptrition on event that will output when event is done
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
 @breif sets on what playerstate event should happend and what it will overwrite with
 @param Playerstate* currentPS the current player state
 @param Playerstate* newPS the new playerstate
 */
void Event::setPlayerState(PlayerState* currentPS, PlayerState* newPS){
	cur_PS = currentPS;
	new_PS = newPS;
}

/**
 @breif sets on what roomstate event should happend(current) and how that state look afterwards
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
 @breif if the event will the player to next room
 @return bool 
 */
bool Event::getMoveToNextRoom() {
	return moveToNextRoom;
}
/**
 @breif set if will move to next room
 @param bool isOnThisEvent 
 */
void Event::setMoveToNextRoom(bool isOnThisEvent) {
	moveToNextRoom = isOnThisEvent;
}
/**
 @breif if this event moves to a barelyEscapable room
 @return bool true if barelyEscapable ELSE false
 */
bool Event::isBarelyEscapable() {
	return barelyEscapable;
}
/**
 @breif sets if the event is an barelyEscapable(like the Inventory)
 @param Room* pointer to the barelyEscapable room
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
 @return Room*  pointer to the barelyEscapable room
 */
Room* Event::getBarelyEscapableRoom() {
	return barelyEscapableRoom;
}
/**
 @breif adds a action the event will trigger after it is fired
 @param OnEventAction is action to be added to event
 */
void Event::setActionOnEvent(OnEventAction action) {
	this->eventActions.push_back(action);
}

/**
 @breif  gets actions the event will triggers
 @return vector<OnEventAction> the vector of actions the event will triggers
 */
std::vector<OnEventAction> Event::getActionOnEvent() {
	return this->eventActions;
}
