#pragma once

#include "item.h"

struct RustedSword : Weapon {
	RustedSword() : Weapon(RUSTED_SWORD, 1, 1, 5, 0) {}
};

struct RustedShield : Weapon {
	RustedShield() : Weapon(RUSTED_SHIELD, 1, 1, 5, 0) {}
};
