#pragma once
#include <vector>
#include <iostream>
#include <string>
//#include "Event.h"
//#include "Player.h"
//#include "StateHolder.h"
//using namespace std;
class Event;
class Player;
class StateHolder;
class RoomState;

enum ROOM_DIRECTIONS { NORTH, EAST, SOUTH, WEST };


class Room : public StateHolder {
	
private:
	RoomState* currentRoomState;
	std::vector<Event> events;
	std::vector<MyLeapAction> allowedActions;
	std::vector<std::string> onActionOutput;
	enum {START,NORMAL,GOAL} roomType;
public:
	Room(void);
	~Room(void);
	void setDescription(int rd, std::string description);
	std::string getDescription(int rd);

	void setEvent(Event e);
	std::vector<Event> getEvents(int);

	void setDoor(int, Room*);
	Room* getDoor(int);

	std::vector<MyLeapAction> getAllowedActions();
	
	virtual void overwrite(State s); // must be implemented
	virtual bool isEqual(State s); // must be implemented
};

