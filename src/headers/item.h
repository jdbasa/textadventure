#pragma once

#include "slot.h"

class Character;

enum Type {
	ARMOR,
	WEAPON,
	OTHER
};

struct Item {
	Item(Type type, int rarity, int speed) :
	type(type), rarity(rarity), speed(speed) {} 

	const Type type;
	const int rarity;
	const int speed;

	virtual ~Item() {}
};

struct Weapon : Item {
	Weapon(int rarity, int speed, int attack, int consumption) :
	Item(WEAPON, rarity, speed), attack(attack), consumption(consumption) {}

	const int attack;
	const int consumption;

	virtual void effect(Character* from) {}
};

struct Armor : Item {
	Armor(int rarity, int speed, Slot slot, int defence, int consumption) :
	Item(ARMOR, rarity, speed), slot(slot), defence(defence), consumption(consumption) {}

	const Slot slot;
	const int defence;
	const int consumption;
	virtual void passive(Character* from, int& incoming_damage) {}
};
