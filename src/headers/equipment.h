#pragma once

#include "inventory.h"
#include "slot.h"

class Equipment {
public:
	Equipment();

	bool equip(Slot slot, ItemType item);
	ItemType get(Slot slot);
private:
	bool fits_slot(Slot slot, ItemType item);

	ItemType* slots;
};
