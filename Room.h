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
	vector<string> description;
	vector<Room> doorlist;
	vector<Event> events;
	vector<MyLeapAction> allowedActions;
	vector<string> onActionOutput;
public:
	Room(void);
	~Room(void);
	void setDescription(int rd, string description);
	string getDescription(int rd);

	void setEvent(Event e, Room newRoom, Player newPlayer, string output);
	vector<Event> getEvents();

	void setDoor(int rd, Room r);
	Room getDoor(int rd);

	bool start;
};

