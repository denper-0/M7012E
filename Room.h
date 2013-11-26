#pragma once
#include <vector>
#include <iostream>
#include "Event.h"
#include "Player.h"
#include "StateHolder.h"
using namespace std;

#include <string>

enum ROOM_DIRECTIONS { NORTH, EAST, SOUTH, WEST };


class Room : public StateHolder {
	
private:
	RoomState currentRoomState;
	vector<Event> events;
	vector<MyLeapAction> allowedActions;
	vector<string> onActionOutput;
	enum {START,NORMAL,GOAL} roomType;
public:
	Room(void);
	~Room(void);
	void setDescription(int rd, string description);
	string getDescription(int rd);

	void setEvent(Event e);
	vector<Event> getEvents(int);

	void setDoor(int, Room*);
	Room* getDoor(int);

	vector<MyLeapAction> getAllowedActions();
	
	virtual void overwrite(State s); // must be implemented
	virtual bool isEqual(State s); // must be implemented
};

