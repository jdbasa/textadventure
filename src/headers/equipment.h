#pragma once

#include "inventory.h"
#include "slot.h"

class Equipment {
public:
	Equipment();

	bool equip(Slot slot, ItemName name);
	ItemName get(Slot slot);
private:
	bool fits_slot(Slot slot, ItemName name);

	ItemName* slots;
};
