#pragma once

#include "item.h"
#include "items.h"

class Inventory {
public:
	Inventory();

	void add(ItemName type);
	bool remove(ItemName type);
	Item* get(ItemName type);

	~Inventory();
private:
	unsigned int* amounts;
};







