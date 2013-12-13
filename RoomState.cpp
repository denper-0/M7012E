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

void RoomState::setDesc(int rd, std::string desc) {
	if(description.size() <= rd) {
		description.resize(rd+1, "");
	}
	description.at(rd) = desc;
}

std::string RoomState::getDesc(int rd){
	if(description.size() <= rd) {
		return "";
	}
	return this->description[rd];

}

void RoomState::setDoor(int dir, Room* door) {
	if(doors.size() <= dir) {
		doors.push_back(door);
		return;
	}
	this->doors[dir] = door;
}

Room* RoomState::getDoor(int dir){
	if(doors.size() <= dir) {
		return NULL;
	}
	return this->doors[dir];
}


int RoomState::getRoomIsLocked() {
	return roomIsLocked;
}
void RoomState::setRoomIsLocked(int locked) {
	roomIsLocked = locked;
}
