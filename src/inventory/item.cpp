#include "item.h"

Item::Item(int rarity, int speed) : rarity(rarity), speed(speed) {}

Weapon::Weapon(int rarity, int speed, int attack, int consumption) :
	Item(rarity, speed), attack(attack), consumption(consumption) {}

Armor::Armor(int rarity, int speed, int defence, int consumption) :
	Item(rarity, speed), defence(defence), consumption(consumption) {}
