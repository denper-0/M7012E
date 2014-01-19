#pragma once
#include <vector>
#include <string>
#include "State.h"

class Room;

enum ROOM_DIRECTIONS { NORTH, EAST, SOUTH, WEST, NO_DIRECTION };
/**
 @breif enum for checking if next room is locked or not */
enum NextRoomState {
	NEXT_ROOM_IS_NULL,
	NEXT_ROOM_IS_LOCKED,
	NEXT_ROOM_IS_UNLOCKED
};

class RoomState : public State
{
private: 
	std::vector<int> items;
	std::vector<int> itemsToRemove;
	std::vector<Room*> doors;
	std::vector<std::string> description;
	int roomIsLocked;
public:
	/**
 @breif constructor for RoomState, sets max doorCount to 4 and if it's locked
 */
	RoomState(void);
	/**
 @breif deconstructor for RoomState, sets max doorCount to 4 and if it's locked
 */
	~RoomState(void);
	/**
 @breif sets roomdescription on the roomstate
 @param int rd This is the facing/direction in the room 
 @param string desc The description text
 */
	void setDesc(int i, std::string s);
	/**
 @breif Returns room description from the roomstate
 @param int rd This is the facing/direction in the room 
 @return string The text description of a certain facing
 */
	std::string getDesc(int i);
	/**
 @breif Sets a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @param the room that is added a door too
 
 */
	void setDoor(int i, Room* r);
	/**
 @breif returns a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @return Room* ELSE NULL Door to next room 
 */
	Room* getDoor(int i);
	/**
 @breif Checks if room is locked
 @return int a int with value if locked or not
 */
	int getRoomIsLocked();
	/**
 @breif locks a room
 @param int locked is the lock value 
 */

	void setRoomIsLocked(int);
};