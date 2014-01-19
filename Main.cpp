#include "Main.h"

//using namespace std;

Main::Main(void) {

}

Main::~Main(void) {

}

int main(void)
{
	Game g;
	g.initLevel();
	return g.looper();
}


