#include <iostream>
#include "inventory.h"

using namespace std;

int main(int args, char** cargs) {
	Inventory inventory;

	inventory.add(RUSTED_SWORD);
	inventory.add(RUSTED_SWORD);
	inventory.add(RUSTED_SWORD);
	inventory.add(RUSTED_SWORD);
	inventory.print(cout);

	return 0;
}
