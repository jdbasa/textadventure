#pragma once

#include "item.h"

enum ItemName {
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

	Item* create(ItemName name);
	Item* get(ItemName name) const;

	~Items();
private:
	Item** items;
};
