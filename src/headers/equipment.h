#pragma once

#include "inventory.h"

enum Slot {
	INVALID = 0,
	HEAD,
	BODY,
	RIGHT_HAND,
	LEFT_HAND,
	LEGS,
	FEET
};

const unsigned int SLOT_COUNT = 7;

class Equipment {
public:
	Equipment();

	bool equip(Slot slot, ItemType item);
	ItemType get(Slot slot);
private:
	bool fits_slot(Slot slot, ItemType item);

	ItemType* slots;
};
