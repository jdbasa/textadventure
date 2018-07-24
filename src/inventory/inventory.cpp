#include "inventory.h"

Inventory::Inventory() {
	amounts = new int[ITEM_COUNT];
	items = new Item*[ITEM_COUNT];

	for (int i = 0; i < ITEM_COUNT; i++) {
		amounts[i] = 0;
		items[i] = 0;
	}
}

void Inventory::add(ItemType type) {
	if (amounts[type] == 0) {
		items[type] = create(type);
	}

	amounts[type]++;
}

bool Inventory::remove(ItemType type) {
	if (amounts[type] == 0) {
		return false;
	}

	amounts[type]--;

	if (amounts[type] == 0) {
		delete items[type];
		items[type] = 0;
	}

	return true;
}

Item* Inventory::get(ItemType type) {
	return items[type];
}

Item* Inventory::create(ItemType type) {
	switch (type) {
		case ItemType::RUSTED_SWORD:
			return 0;
		case ItemType::RUSTED_SHEILD:
			return 0;
		default:
			return 0;
	}
}

Inventory::~Inventory() {
	delete[] amounts;

	for (int i = 0; i < ITEM_COUNT; i++) {
		if (items[i]) delete items[i];
	}
	delete[] items;
}
