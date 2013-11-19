#pragma once
#include <list>
#include <iostream>
using namespace std;

class Room{
	string description [3];
public:
	list<Room> doorlist;
	void set_Description(int, string);
	void set_Event();
	bool start;
};

