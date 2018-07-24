#pragma once

#include "item.h"

enum ItemType {
	NONE = 0,
	RUSTED_SWORD,
	RUSTED_SHEILD,
	RUSTED_HELMET
};

const int ITEM_COUNT = 3;

class Inventory {
public:
	static bool is_armor(ItemType item);

	Inventory();

	void add(ItemType type);
	bool remove(ItemType type);
	Item* get(ItemType type);

	~Inventory();
private:
	Item* create(ItemType type);

	int* amounts;
	Item** items;
};
