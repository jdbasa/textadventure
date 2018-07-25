#include "area.h"
#include "items.h"

using namespace std;

Area::Area() : init(false), level(0) {
}

Area::~Area() {
	delete[] floor_items;
	delete[] amounts;
}

bool Area::pick_up(Character& character, ItemName name) {
	if (!remove(name)) {
		return false;
	}

	character.inventory.add(name);
	return true;
}

void Area::print(ostream& out) {
	for (unsigned int i = 0; i < item_count; i++) {
		if (!amounts[i]) continue;
		out << Items::instance.to_string(floor_items[i]) << " " << amounts[i] << endl;
	}
}

void Area::generate(unsigned int level) {
	this->level = level;

	init = true;

	item_count = 3;
	floor_items = new ItemName[item_count];
	amounts = new unsigned int[item_count];

	for (unsigned int i = 0; i < item_count; i++) {
		floor_items[i] = RUSTED_SWORD;
		amounts[i] = 1;
	}
}

bool Area::initialized() {
	return init;
}

unsigned int Area::get_level() {
	return level;
}

bool Area::remove(ItemName name) {
	for (unsigned int i = 0; i < item_count; i++) {
		if (floor_items[i] != name || amounts[i] == 0) {
			continue;
		}

		amounts[i]--;
		return true;
	}

	return false;
}





