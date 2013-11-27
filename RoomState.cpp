#include "RoomState.h"


RoomState::RoomState(void)
{

}

RoomState::~RoomState(void)
{
}

void RoomState::setDesc(int rd, std::string desc){
	this->description[rd] = desc;
}

std::string RoomState::getDesc(int rd){
	return this->description[rd];

}

void RoomState::setDoor(int dir, Room* door){
	this->doors[dir] = door;

}

Room* RoomState::getDoor(int dir){
	return this->doors[dir];
}