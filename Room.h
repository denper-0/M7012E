#pragma once
#include <vector>
#include <iostream>
#include "Event.h"
#include "Player.h"
using namespace std;

#include <string>

enum ROOM_DIRECTIONS { NORTH, EAST, SOUTH, WEST };


class Room{
	
private:
	vector<string> description;
	vector<Room*> doors;
	vector<Event> events;
	vector<MyLeapAction> allowedActions;
	vector<string> onActionOutput;
public:
	Room(void);
	~Room(void);
	void setDescription(int rd, string description);
	string getDescription(int rd);

	void setEvent(Event e);
	vector<Event> getEvents();

	void setDoor(int, Room*);
	Room* getDoor(int);

	bool start;
};

