#pragma once
#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

#include "MyLeap.h"
#include "Gametext.h"

#include "Room.h"
#include "Event.h"
#include "PlayerState.h"
#include "RoomState.h"
#include "Player.h"

class Game
{
public:
	Game(void);
	~Game(void);
	void initLevel();
	int looper();
	void printText(std::string str);
private:
	MyLeap* L;
	Room* currentRoom;
	Player* currentPlayer;
	Gametext *generalText;
	Gametext *descText;
	Gametext *itemText;
	enum DECORATE_ROOM_OPTION {DECORATE_ROTATE_ROOM_LEFT, DECORATE_ROTATE_ROOM_RIGHT};
	void decorateRoom(Room *r, int options, std::string texts);
	void connectRooms(Room *r1, Room *r2, int firstRoomsDirection);
	void setEventOnDoor(Room* r, int direction, std::string output = "");
	Event* createInventory();
	/**
	*	@breif runLoopOnRoom
		@return Room*  sometimes NULL used to indicating for barelyEscapableEvent when it is escaped. Otherwise the current Room. 
	*/
	Room* Game::runLoopOnRoom(Room *);
};

