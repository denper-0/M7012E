#pragma once
#include <string>
#include <vector>
//#include "MyLeap.h"
//#include "RoomState.h"
//#include "PlayerState.h"
//#include "Room.h"
class MyLeap;
class RoomState;
class PlayerState;
class Room;
enum MyLeapAction;
/**
 * @breif actions after the event is triggered
 */
enum OnEventAction {
	ON_EVENT_NO_ACTION,
	ON_EVENT_ITERATE_ITEMS_LEFT,
	ON_EVENT_ITERATE_ITEMS_RIGHT,
	ON_EVENT_ITERATE_FACING_LEFT,
	ON_EVENT_ITERATE_FACING_RIGHT,
	ON_EVENT_PRINT_CURRENT_ITEM,
	ON_EVENT_PRINT_DIRECTION
};
/**
 * @breif holds a action the game loop will trigger on combined with the current states the game loop will check with agains current room and player. Will finaly overwrite with the other tho states, give the events output and trigger actions. 
 */
class Event
{
private:
	MyLeapAction action;
	std::string eventText;
	PlayerState* cur_PS;
	PlayerState* new_PS;
	RoomState* cur_RS;
	RoomState* new_RS;
	bool moveToNextRoom;
	bool barelyEscapable;
	Room* barelyEscapableRoom;
	std::vector<OnEventAction> eventActions;


public:
/**
 @breif constructs a event with some properties set, rest are set to deafult meaning no change if it fires
 @param MyLeapAction* on what action the event fires
 @param PlayerState* current player state the game loop overwrites with
 @param RoomState* current room state the game loop verifies with
 @param PlayerState* new room state the game loop overwrites with
 @param RoomState* new room state the game loop overwrites with
 @param string eventStr text for the event
 */
	Event(MyLeapAction, PlayerState*, RoomState*, PlayerState*, RoomState*, std::string);
/**
 * @breif destructor
 */
	~Event(void);
/**
 @breif set text/desciptrition on event that will output when event is done
 @param string eventStr text for the event
 */
	void setText(std::string);
/**
 @breif returns text for event/description
 @return string event text
 */
	std::string getText();
/**
 @breif sets on what playerstate event should happend and what it will overwrite with
 @param Playerstate* currentPS the current player state
 @param Playerstate* newPS the new playerstate
 */
	void setPlayerState(PlayerState* currentRS, PlayerState* newRS);
/**
 @breif sets on what roomstate event should happend(current) and how that state look afterwards
 @param Roomstate* currentRS the current player state
 @param Roomstate* newRS the new playerstate
 */
	void setRoomState(RoomState* currentRS, RoomState* newRS);
/**
 @breif returns the new playerstate
 @return Playerstate* new_PS variable
 */
	PlayerState* getNewPlayerstate();
/**
 @breif returns the new Roomstate
 @return Roomstate* new_RS variable
 */
	RoomState* getNewRoomstate();
/**
 @breif returns the current playerstate
 @return Playerstate* current_PS variable
 */
	PlayerState* getCurrentPlayerstate();
/**
 @breif returns the current Roomstate
 @return Roomstate* current_RS variable
 */
	RoomState* getCurrentRoomstate();
/**
 @breif returns the action that the event triggers on
 @return MyLeapAction action
 */
	MyLeapAction getAction();
/**
 @breif if the event will the player to next room
 @return bool 
 */
	bool getMoveToNextRoom();
/**
 @breif set if will move to next room
 @param bool isOnThisEvent 
 */
	void setMoveToNextRoom(bool isOnThisEvent);
/**
 @breif if this event moves to a barelyEscapable room
 @return bool true if barelyEscapable ELSE false
 */
	bool isBarelyEscapable();
/**
 @breif sets if the event is an barelyEscapable(like the Inventory)
 @param Room* pointer to the barelyEscapable room
 */
	void setBarelyEscapable(Room *barelyEscapableRoom);

/**
 @breif returns barelyEscapableRoom variable
 @return Room*  pointer to the barelyEscapable room
 */
	Room* getBarelyEscapableRoom();
/**
 @breif adds a action the event will trigger after it is fired
 @param OnEventAction is action to be added to event
 */
	void setActionOnEvent(OnEventAction action);
/**
 @breif  gets actions the event will triggers
 @return vector<OnEventAction> the vector of actions the event will triggers
 */
	std::vector<OnEventAction> getActionOnEvent();
};

