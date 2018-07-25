#pragma once

#include <iostream>
#include <string>
#include <map>
#include "character.h"
#include "command.h"

class Game {
public:
	Game();
	~Game() {}
	Map map;

	void update();

private:
	bool run_command(std::istream& in, std::ostream& out);
	Commands::Command next_command(std::istream& in);

	void walk(std::istream& in, std::ostream& out);

	bool try_get_command(std::string str, Commands::Command& command);
	std::map<std::string, Commands::Command> string_command;
};
