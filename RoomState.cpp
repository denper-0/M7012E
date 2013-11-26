#include "RoomState.h"


RoomState::RoomState(void)
{
	
}


RoomState::~RoomState(void)
{
}

void RoomState::setDesc(string desc){
		this->description = desc;
}

string RoomState::getDesc(){
	return this->description;

}

void RoomState::setDoors(int dir, Room door){
	this->doors[dir] = door;

}

Room RoomState::getDoors(int dir){
		return this->doors[dir];

}