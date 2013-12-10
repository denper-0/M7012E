#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
//using namespace std;

class Gametext
{
public:
	Gametext(std::string fileName = "textToGame.txt");
	~Gametext(void);
	std::string getText(int id);
private:
	std::string line;
	std::vector<std::string> text;
	std::string fileName;
	void readFile(std::string fileName);
};