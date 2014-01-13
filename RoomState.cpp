#include "RoomState.h"


RoomState::RoomState(void)
{
	doors.resize(4);
	//description.resize(5);
	roomIsLocked = 0;
}

RoomState::~RoomState(void)
{
}
/**
 @breif sets roomdescription on the roomstate
 @param int rd This is the facing/direction in the room 
 @param string desc The description text
 */
void RoomState::setDesc(int rd, std::string desc) {
	if(description.size() <= rd) {
		description.resize(rd+1, "");
	}
	description.at(rd) = desc;
}

/**
 @breif Returns room description from the roomstate
 @param int rd This is the facing/direction in the room 
 @return string The text description of a certain facing
 */
std::string RoomState::getDesc(int rd){
	if(description.size() <= rd) {
		return "";
	}
	return this->description[rd];

}

/**
 @breif Sets a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @param the room that is added a door too
 
 */
void RoomState::setDoor(int dir, Room* door) {
	if(doors.size() <= dir) {
		doors.push_back(door);
		return;
	}
	this->doors[dir] = door;
}

/**
 @breif returns a room as a door in a roomstate at a certain direction
 @param int dir is the direction facing in the room 
 @return Room* ELSE NULL Door to next room 
 */
Room* RoomState::getDoor(int dir){
	if(doors.size() <= dir) {
		return NULL;
	}
	return this->doors[dir];
}

/**
 @breif Checks if room is locked
 @return int a int with value if locked or not
 */
int RoomState::getRoomIsLocked() {
	return roomIsLocked;
}

/**
 @breif locks a room
 @param int locked is the lock value 
 */

void RoomState::setRoomIsLocked(int locked) {
	roomIsLocked = locked;
}
