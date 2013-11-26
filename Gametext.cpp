#include "Gametext.h"

Gametext::Gametext(void)
{
	fstream myFile("textToGame.txt", ios::in);
	if (!myFile) {
		cerr << "Error opening file." << "textToGame.txt" << endl;
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

string Gametext::getText(int id) {
	return text[id];
	
}