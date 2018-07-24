#pragma once

#include <ostream>
#include "item_name.h"

class Area {
public:
	Area(unsigned int level);
	~Area();

	void print(std::ostream& out);
private:
	void generate();

	const unsigned int level;

	unsigned int item_count;
	ItemName* floor_items;
	unsigned int* amounts;
};
