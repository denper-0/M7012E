#pragma once
//#include "State.h"
#include "MyLeap.h"
#include "StateHolder.h"
#include "Room.h"
#include "Player.h"
#include "Gametext.h"
#include "RoomState.h"
#include "PlayerState.h"
#include "Event.h"


#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

//using namespace std;

class Game
{
public:
	Game(void);
	~Game(void);
	void initLevel();
	int looper();
	void printText(std::string str);
private:
	Room *currentRoom;
	Player *currentPlayer;
	Gametext *text;
	enum DECORATE_ROOM_OPTION {DECORATE_ROTATE_ROOM_LEFT, DECORATE_ROTATE_ROOM_RIGHT};
	Room decorateRoom(Room *r, int options, std::string texts);
	void connectRooms(Room *r1, Room *r2, int firstRoomsDirection);
};

