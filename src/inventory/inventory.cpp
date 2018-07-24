#include "inventory.h"
#include "items.h"

using namespace std;

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

Item* Inventory::get(ItemName name) const {
	return Items::instance.get(name);
}

unsigned int Inventory::amount(ItemName name) const {
	return amounts[name];
}

void Inventory::print(ostream& out) {
	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		unsigned int amount = this->amount((ItemName)i);
		if (!amount) continue;
		out << Items::instance.to_string((ItemName)i) << " " << amount << endl;
	}
}

Inventory::~Inventory() {
	delete[] amounts;
}
