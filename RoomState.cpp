#include "RoomState.h"


RoomState::RoomState(void)
{
	description.resize(4);
}

RoomState::~RoomState(void)
{
}

void RoomState::setDesc(int rd, string desc){
	this->description[rd] = desc;
}

string RoomState::getDesc(int rd){
	return this->description[rd];

}

void RoomState::setDoor(int dir, Room door){
	this->doors[dir] = door;

}

Room RoomState::getDoor(int dir){
	return this->doors[dir];
}