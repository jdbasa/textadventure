#include "area.h"
#include "items.h"

using namespace std;

Area::Area(unsigned int level) : level(level) {
	generate();
}

Area::~Area() {
	delete[] floor_items;
	delete[] amounts;
}

void Area::print(ostream& out) {
	for (unsigned int i = 0; i < item_count; i++) {
		if (!amounts[i]) continue;
		out << Items::instance.to_string(floor_items[i]) << " " << amounts[i] << endl;
	}
}

void Area::generate() {
	item_count = 3;
	floor_items = new ItemName[item_count];
	amounts = new unsigned int[item_count];

	for (unsigned int i = 0; i < item_count; i++) {
		floor_items[i] = RUSTED_SWORD;
		amounts[i] = 1;
	}
}
