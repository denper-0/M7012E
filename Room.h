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
/**
 @breif returns a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @param string desc the description
 */
	void setDescription(int rd, std::string description);
/**
 @breif returns a description
 @param int dir is the direction facing in the room 
 @return 
 */
	std::string getDescription(int rd);
/**
 @breif add event to the event vector
 @param Event* e the event to be added 
 */
	void setEvent(Event* e);
/**
 @breif returns event on action
 @param int action an action that occured
 @return vector<Event*> returns vector with event connected to action
 */
	std::vector<Event*> getEvents(int);
/**
 @breif adds door
 @param int rd direction in the room
 @param Room* r the room that the door is going to lead to
 */
	void setDoor(int, Room*);
/**
 @breif returns the room the door is connected to
 @param int dir is the direction facing in the room 
 @return Room* room the door is connected too 
 */
	Room* getDoor(int);
/**
 @breif returns what action the room's event's react too 
 @return vector<MyLeapAction> vector with allowed action for the event in a room
 */
	std::vector<MyLeapAction> getAllowedActions();
/**
 @breif returns roomId
 @return int the rooms id 
 */
	int getRoomId();
/**
 @breif adds item to room
 @param int dir is the direction facing in the room 
 */
	void setItem(int i, int itemId);
/**
 @breif overwrites this room's state with given roomstate, NULL IGNORES
 @param State* s roomstate to overwrite with
 @param State* s2 the Playerstate to know facing 
 */	
	virtual void overWrite(State* s, State* s2); // must be implemented
/**
 @breif checks if this room's state is equal to the given roomstate
 @param State* s roomstate to compare with
 @param State* s2 the Playerstate to know facing 
 @return boolean if equal true ELSE false
 */
	virtual bool isEqual(State* s, State* s2); // must be implemented

/**
 @breif overwrites this room's state with given roomstate, NULL IGNORES
 @param State* s roomstate to overwrite with
 @param State* s2 the Playerstate to know facing 
 */	
	int getRoomIsLocked();
/**
 @breif sets a rooms isLocked variable to locked/unlocked
 @param int locked is locked/unlocked
 */
	void setRoomIsLocked(int);
/**
 @breif returns the current state for the room
 @return State* current stat for the room
 */
	State* getState();
};

