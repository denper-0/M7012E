#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Gametext
{
public:
	Gametext(void);
	~Gametext(void);
	string getText(int id);
private:
	string line;
	vector<string> text;
};