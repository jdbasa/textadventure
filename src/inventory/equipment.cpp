#include "equipment.h"
#include "items.h"

Equipment::Equipment() {
	slots = new ItemType[SLOT_COUNT];
	for (unsigned int i = 0; i < SLOT_COUNT; i++) {
		slots[i] = NONE; 
	}
}

bool Equipment::equip(Slot slot, ItemType item) {
	if (!fits_slot(slot, item)) {
		return false;
	}

	slots[slot] = item;
	return true;
}

ItemType Equipment::get(Slot slot) {
	return slots[slot];
}

bool Equipment::fits_slot(Slot slot, ItemType name) {
	Item* item = Items::instance.get(name);

	if (item->type != ARMOR) return false;

	return ((Armor*)item)->slot == slot;
	
}
