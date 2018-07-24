#pragma once

#include "item.h"
#include "items.h"

class Inventory {
public:
	Inventory();

	void add(ItemType type);
	bool remove(ItemType type);
	Item* get(ItemType type);

	~Inventory();
private:
	unsigned int* amounts;
};







