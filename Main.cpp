#include "Main.h"
#include "Room.h"
#include <iostream>
using namespace std;



int main(void)
{
	Controller controller;
	if( controller.isConnected()) //controller is a Controller object
        {
                Frame frame = controller.frame(); //The latest frame
                Frame previous = controller.frame(1); //The previous frame
        }
	return 0;
	
		

}


