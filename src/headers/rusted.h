#pragma once

#include "item.h"

struct RustedSword : Weapon {
	RustedSword() : Weapon(1, 1, 5, 0) {}
};

struct RustedShield : Weapon {
	RustedShield() : Weapon(1, 1, 5, 0) {}
};
