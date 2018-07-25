#include <iostream>
#include "area.h"
#include "character.h"
#include "command.h"
#include "game.h"

using namespace std;

int main(int args, char** cargs) {
	Area area(1);
	Character character;

	area.print(cout);
	cout << "n" << endl;
	character.inventory.print(cout);
	cout << "e" << endl;

	area.pick_up(character, RUSTED_SWORD);

	area.print(cout);
	cout << "n" << endl;
	character.inventory.print(cout);
	cout << "e" << endl;

	Game game;
	Commands::Command comm = game.get_command(cin);

	cout << "The command from main is: " << comm << endl;

	return 0;
}
