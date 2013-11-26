#include "Event.h"


Event::Event(MyLeapAction a, PlayerState current_PS, PlayerState newPS, RoomState current_RS, RoomState newRS, string eText) {
	action = a;
	cur_PS = current_PS;
	new_PS = newPS;
	cur_RS = current_RS;
	new_RS = newRS;
	eventText = eText;
}

Event::~Event(void) {

}

void Event::setText(string eventStr){
	eventText = eventStr;
}

string Event::getText(){
	 return eventText;
}

void Event::setPlayerState(PlayerState currentPS, PlayerState newPS){
	cur_PS = currentPS;
	new_PS = newPS;
}

void Event::setRoomState(RoomState currentRS,RoomState newRS){
	cur_RS = currentRS;
	new_RS = newRS;
}

PlayerState Event::getNewPlayerstate() {
	return new_PS;
}

RoomState Event::getNewRoomstate() {
	return new_RS;
}
PlayerState Event::getCurrentPlayerstate() {
	return cur_PS;
}

RoomState Event::getCurrentRoomstate() {
	return cur_RS;
}

MyLeapAction Event::getAction() {
	return action;
}