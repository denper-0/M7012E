#pragma once
#include <vector>
#include <iostream>
#include <string>
//#include "Event.h"
//#include "Player.h"
#include "StateHolder.h"
#include "RoomState.h"
#include "PlayerState.h"
#include "Event.h"
//using namespace std;

class Player;
class StateHolder;
enum MyLeapAction;

class Room : public StateHolder {
	
private:
	RoomState* currentRoomState;
	std::vector<Event*> events;
	std::vector<MyLeapAction> allowedActions;
	std::vector<std::string> onActionOutput;
	enum {START,NORMAL,GOAL} roomType;
	int roomId;
public:
	Room(int id);
	~Room(void);
	void setDescription(int rd, std::string description);
	std::string getDescription(int rd);

	void setEvent(Event* e);
	std::vector<Event*> getEvents(int);

	void setDoor(int, Room*);
	Room* getDoor(int);

	std::vector<MyLeapAction> getAllowedActions();

	int getRoomId();

	void setItem(int i, int itemId);
	
	virtual void overWrite(State* s, State* s2); // must be implemented
	virtual bool isEqual(State* s, State* s2); // must be implemented

	
	int getRoomIsLocked();
	void setRoomIsLocked(int);
	State* getState();
};

