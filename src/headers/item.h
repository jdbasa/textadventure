#pragma once

#include "slot.h"
#include "item_name.h"

class Character;

enum ItemType {
	ARMOR,
	WEAPON,
	OTHER
};

struct Item {
	Item(ItemName name, ItemType type, int rarity, int speed) :
	name(name), type(type), rarity(rarity), speed(speed) {} 

	const ItemName name;
	const ItemType type;
	const int rarity;
	const int speed;

	virtual ~Item() {}
};

struct Weapon : Item {
	Weapon(ItemName name, int rarity, int speed, int attack, int consumption) :
	Item(name, WEAPON, rarity, speed), attack(attack), consumption(consumption) {}

	const int attack;
	const int consumption;

	virtual void effect(Character* from) {}
};

struct Armor : Item {
	Armor(ItemName name, int rarity, int speed, Slot slot, int defence, int consumption) :
	Item(name, ARMOR, rarity, speed), slot(slot), defence(defence), consumption(consumption) {}

	const Slot slot;
	const int defence;
	const int consumption;
	virtual void passive(Character* from, int& incoming_damage) {}
};
