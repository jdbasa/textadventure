#pragma once

#include <ostream>
#include "item_name.h"
#include "character.h"

class Area {
public:
	Area(unsigned int level);
	~Area();

	bool pick_up(Character& character, ItemName name);

	void print(std::ostream& out);
private:
	void generate();
	bool remove(ItemName name);

	const unsigned int level;

	unsigned int item_count;
	ItemName* floor_items;
	unsigned int* amounts;
};
