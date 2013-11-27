#include "Gametext.h"

Gametext::Gametext(void)
{
	std::fstream myFile("textToGame.txt", std::ios::in);
	if (!myFile) {
		std::cerr << "Error opening file." << "textToGame.txt" << std::endl;
		exit(1);
	}
	
	while (getline(myFile, line)){
		text.push_back(line);
	}
	myFile.close();
}


Gametext::~Gametext(void)
{
}

std::string Gametext::getText(int id) {
	return text[id];
	
}