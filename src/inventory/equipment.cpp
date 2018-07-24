#include "equipment.h"
#include "items.h"

Equipment::Equipment() {
	slots = new ItemName[SLOT_COUNT];
	for (unsigned int i = 0; i < SLOT_COUNT; i++) {
		slots[i] = NONE; 
	}
}

bool Equipment::equip(Slot slot, ItemName name) {
	if (!fits_slot(slot, name)) {
		return false;
	}

	slots[slot] = name;
	return true;
}

ItemName Equipment::get(Slot slot) {
	return slots[slot];
}

bool Equipment::fits_slot(Slot slot, ItemName name) {
	Item* item = Items::instance.get(name);

	if (item->type != ARMOR) return false;

	return ((Armor*)item)->slot == slot;
	
}
