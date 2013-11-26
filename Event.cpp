#include "Event.h"
#include "RoomState.h"
#include "PlayerState.h"


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

	eventText = eventStr;
}

string getEventText(){

	 return eventText;
}

void setPlayerstate(PlayerState currentPS,PlayerState newPS){
	cur_PS = currentPS;
	new_PS = newPS;
}

void setPlayerstate(PlayerState currentRS,PlayerState newRS){
	cur_RS = currentRS;
	new_RS = newRS;
}