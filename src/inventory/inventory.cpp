#include "inventory.h"

Inventory::Inventory() {
	amounts = new unsigned int[ITEM_COUNT];

	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		amounts[i] = 0;
	}
}

void Inventory::add(ItemType type) {
	amounts[type]++;
}

bool Inventory::remove(ItemType type) {
	if (amounts[type] == 0) {
		return false;
	}

	amounts[type]--;

	return true;
}

Item* Inventory::get(ItemType type) {
	return 0;
}

Inventory::~Inventory() {
	delete[] amounts;
}
