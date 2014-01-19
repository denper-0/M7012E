#pragma once
#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


#include "MyLeap.h"
#include "Gametext.h"

#include "Room.h"
#include "Event.h"
#include "PlayerState.h"
#include "RoomState.h"
#include "Player.h"
/**
 *  @breif holds the level initization (change in future!) and the game loop
 */
class Game
{
public:
/**
 @breif constructor for the game
 */
	Game(void);
/**
 @breif descructor for the game
 */
	~Game(void);
/**
 @breif creates and connects all the rooms and adds descriptions to rooms and it's directions
 */
	void initLevel();
/**
 @breif starts the game loop that iterates 
 */
	int looper();
/**
 @breif prints out every character with a small delay, formats text and handles newline
 @param string str String to print out
 */
	void printText(std::string str);
private:
	MyLeap* L;
	Room* currentRoom;
	Player* currentPlayer;
	Gametext *generalText;
	Gametext *descText;
	Gametext *itemText;
	enum DECORATE_ROOM_OPTION {DECORATE_ROTATE_ROOM_LEFT, DECORATE_ROTATE_ROOM_RIGHT};
/**
 @breif add common text event to left and right swipe
 @param Room* r which room to add event too
 @param int option if event is connected to right or left swipe
 @param string text description output added to the event
 */
	void decorateRoom(Room *r, int options, std::string texts);
/**
 @breif connects rooms to each other so they can be travelled between
 @param Room* r1 room connects with room r2
 @param Room* r2 room connects to room r1
 @param int firstroomsDirectionn which door/direction in room r1 leads to room r2
 */
	void connectRooms(Room *r1, Room *r2, int firstRoomsDirection);
/**
 @breif add event to a door
 @param Room* r which room to add event too
 @param int direction which door in the room to connect event to
 @param string output text output when event is trigger on door
 */
	void setEventOnDoor(Room* r, int direction, std::string output = "");
/**
 @breif creates the inventory and all it's functionalities
 @return Event* InventoryEvent event which moves the player to the "inventory room"/barelyEscapable
 */
	Event* createInventory();
/**
 * @breif method for the game loop to do a single iteration on a room. It also recursivly goes into a barelyEscapable room
 * @return the room the player currently occupyes after the iteration or NULL if the player exited a barelyEscapable room. 
 */
	Room* Game::runLoopOnRoom(Room *);
};

