#include <iostream>
#include "area.h"
#include "character.h"

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





	return 0;
}
