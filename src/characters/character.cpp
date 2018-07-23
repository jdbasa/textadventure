#include <algorithm>
#include "character.h"

using namespace std;

int Character::get_level() {
	return level;
}

int Character::get_health() {
	return health;
}

int Character::deal(int damage) {
	health = max(health - damage, 0);

	return health;
}

int Character::gain(int heal) {
	health = max(health + heal, max_health);

	return health;
}

int Character::get_magic() {
	return magic;
}

bool Character::consume(int mana) {
	if (mana > magic) {
		return false;
	}

	magic -= mana;
	
	return true;
}

int Character::regain(int mana) {
	magic = min(magic + mana, max_magic);

	return magic;
}
