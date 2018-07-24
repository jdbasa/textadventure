#pragma once

#include <ostream>
#include "item.h"
#include "items.h"

class Inventory {
public:
	Inventory();

	void add(ItemName name);
	bool remove(ItemName name);
	Item* get(ItemName name) const ;
	unsigned int amount(ItemName name) const;
	
	void print(std::ostream& out);

	~Inventory();
private:
	unsigned int* amounts;
};







