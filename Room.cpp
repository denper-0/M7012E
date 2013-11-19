// function template
#include "Room.h"
#include <iostream>
using namespace std;
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <fstream>
#include <list>




void Room::set_Description(int count, string desc){
	Room::description[count] = desc;
}

void Room::set_Event(){
	
}

int Room::printText(string str){

	for (unsigned i = 0; i < str.length(); i++)
  {
    cout << str[i];
    if((i + 1) < str.length() && str[i+1] != '\n')
      cout << char(219);
    Sleep(50);
    if((i + 1) < str.length() && str[i+1] != '\n')
      cout << char(8);
  }
  cout << ' ' << char(8); 
  return(0);

}

void Room::tomte() {
  
	string name;
	string hej = "Hallo Elleh!\n";
	string name1 = "What's your name?\n";
	string douche = "!?!? What a silly name!\n\n";
	string silly = name+douche;

	printText(hej);
	printText(name1);
	printText("My name is ");
	getline(cin, name);
	printText(name);
	printText(silly);
	getchar();

}



  

 

  /* some possible cursors */
  /*
20
  for (unsigned i = 176; i < 179; i++)
21
    cout << char(i) << ' ';
22
  cout << endl;
23
 
24
  for (unsigned i = 219; i < 223; i++)
25
    cout << char(i) << ' ';
26
  cout << endl;
27
  */
  
