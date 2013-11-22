#pragma once

//#include <WinUser.h>
#include <fstream>
#include "MyLeap.h"
#include <windows.h>
#include <vector>
#include "Room.h"
#include <iostream>
using namespace std;

class Main
{
public:
	Main(void);
	~Main(void);
	int printText(string); 
	void looper(); 
};
