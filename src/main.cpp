#include <iostream>
#include "command.h"
#include "game.h"

using namespace std;

int main(int args, char** cargs) {
	Game game;
	game.update();

	//cout << "The command from main is: " << comm << endl;
	return 0;
}
