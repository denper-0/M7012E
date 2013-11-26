#include "Event.h"



Event::Event(MyLeapAction a, PlayerState current_PS, PlayerState newPS, RoomState current_RS, RoomState newRS, string eText) {
	action = a;
	cur_PS = current_PS;
	new_PS = newPS;
	cur_RS = current_PS;
	new_RS = newRS;
	eventText = eText;
}

Event::~Event(void) {

}

void setEventText(string eventStr){

	Event::eventText = eventStr;
}

string getEventText(){

	 return Event::eventText;
}

void setPlayerstate(PlayerState current_PS,PlayerState newPS){
	Event::cur_PS = currentPS;
	Event::new_PS = newPS;
}

void setPlayerstate(PlayerState current_PS,PlayerState newPS){
	Event::cur_RS = currentRS;
	Event::new_RS = newRS;
}