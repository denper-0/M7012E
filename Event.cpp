#include "Event.h"



Event::Event(void) {

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