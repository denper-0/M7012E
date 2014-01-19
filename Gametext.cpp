#include "Gametext.h"

Gametext::Gametext(std::string fileName)
{
	this->fileName = fileName;
	readFile(fileName);
}


Gametext::~Gametext(void)
{
}

void Gametext::readFile(std::string fileName) {
	
	std::fstream myFile(fileName, std::ios::in);
	if (!myFile) {
		std::cerr << "Error opening file." << "textToGame.txt" << std::endl;
		exit(1);
	}
	
	while (getline(myFile, line)){
		text.push_back(line);
	}
	myFile.close();
}

std::string Gametext::getText(int id) {
	if(text.size() < id || id < 0) {
		return "no text exists!";
	}
	return text[id];
	
}