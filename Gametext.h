#pragma once
#include <string>
#include <vector>
using namespace std;

class Gametext
{
public:
	Gametext(void);
	~Gametext(void);
	string getText(int id);
private:
	vector<string> text;
};

