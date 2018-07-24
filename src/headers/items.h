#pragma once

#include <string>
#include "item.h"
#include "item_name.h"

const unsigned int ITEM_COUNT = 3;

class Items {
public:
	static const Items instance;

	Items();

	Item* create(ItemName name);
	Item* get(ItemName name) const;

	std::string to_string(ItemName name) const;

	~Items();
private:
	Item** items;
};
