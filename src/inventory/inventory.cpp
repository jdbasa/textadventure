#include "inventory.h"

Inventory::Inventory() {
	amounts = new unsigned int[ITEM_COUNT];

	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		amounts[i] = 0;
	}
}

void Inventory::add(ItemName name) {
	amounts[name]++;
}

bool Inventory::remove(ItemName name) {
	if (amounts[name] == 0) {
		return false;
	}

	amounts[name]--;

	return true;
}

Item* Inventory::get(ItemName name) {
	return 0;
}

Inventory::~Inventory() {
	delete[] amounts;
}
