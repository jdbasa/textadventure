#pragma once

#include <istream>
#include "character.h"
#include "command.h"

class Game {
public:
	Character player;
	void update();

	Commands::Command get_command(std::istream& in);
};
