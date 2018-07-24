#pragma once

#include "item.h"

enum ItemType {
	NONE = 0,
	RUSTED_SWORD,
	RUSTED_SHIELD,
	RUSTED_HELMET
};

const unsigned int ITEM_COUNT = 3;

class Items {
public:
	static const Items instance;

	Items();

	Item* create(ItemType name);
	Item* get(ItemType name) const;

	~Items();
private:
	Item** items;
};
