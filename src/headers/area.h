#pragma once

#include <ostream>
#include "item_name.h"
#include "character.h"

class Area {
public:
	Area();
	~Area();

	bool pick_up(Character& character, ItemName name);
	void generate(unsigned int level);

	bool initialized();
	unsigned int get_level();

	void print(std::ostream& out);
private:
	bool remove(ItemName name);

	bool init;
	unsigned int level;

	unsigned int item_count;
	ItemName* floor_items;
	unsigned int* amounts;
};
