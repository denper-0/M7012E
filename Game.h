#pragma once
#include "Room.h"
#include "Player.h"
#include "Gametext.h"
using namespace std;

class Game
{
public:
	Game(void);
	~Game(void);
	void initLevel();
	void looper();
private:
	Room *currentRoom;
	Player *currentPlayer;
	Gametext *text;
	enum DECORATE_ROOM_OPTION {DECORATE_ROTATE_ROOM_LEFT, DECORATE_ROTATE_ROOM_RIGHT};
	Room decorateRoom(Room *r, int options, string texts);
	void connectRooms(Room *r1, Room *r2, int firstRoomsDirection);
};

