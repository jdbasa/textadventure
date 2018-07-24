#pragma once

#include "inventory.h"
#include "equipment.h"

class Character {
public:
	Inventory inventory;
	Equipment equipment;

	int get_health() const;
	int deal(int damage);
	int gain(int heal);

	int get_magic() const;
	bool consume(int mana);
	int regain(int mana);
private:
	int max_health;
	int health;

	int max_magic;
	int magic;
};
