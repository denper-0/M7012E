#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
//using namespace std;
/**
 *  @breif holds text lines associated with their id's a.k.a. the line from the text file. starting with 0. 
 */
class Gametext
{
public:
	Gametext(std::string fileName = "textToGame.txt");
	~Gametext(void);
/**
 @breif returns textline from the list
 @return string
 */
	std::string getText(int id);
private:
	std::string line;
	std::vector<std::string> text;
	std::string fileName;
/**
 @breif reads text from file, line by line and add it to a list.
 */
	void readFile(std::string fileName);
};