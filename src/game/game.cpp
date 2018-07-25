#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include "command.h"
#include "game.h"

using namespace std;

Game::Game() {
	string_command.insert(pair<string, Commands::Command> 
			("walk", Commands::WALK));
	string_command.insert(pair<string, Commands::Command> 
			("inventory", Commands::INVENTORY));
	string_command.insert(pair<string, Commands::Command> 
			("armor", Commands::ARMOR));
	string_command.insert(pair<string, Commands::Command> 
			("weapon", Commands::WEAPON));
	string_command.insert(pair<string, Commands::Command> 
			("info", Commands::INFO));
	string_command.insert(pair<string, Commands::Command> 
			("equip", Commands::EQUIP));
	string_command.insert(pair<string, Commands::Command> 
			("pick_up", Commands::PICK_UP));
	string_command.insert(pair<string, Commands::Command> 
			("drop", Commands::DROP));
	string_command.insert(pair<string, Commands::Command> 
			("north", Commands::NORTH));
	string_command.insert(pair<string, Commands::Command> 
			("south", Commands::SOUTH));
	string_command.insert(pair<string, Commands::Command> 
			("east", Commands::EAST));
	string_command.insert(pair<string, Commands::Command> 
			("west", Commands::WEST));
	string_command.insert(pair<string, Commands::Command> 
			("quit", Commands::QUIT));

}

void Game::update() {
	cout << "Type in a command, use *help* to get started." << endl;
	do {
		cout << ">> ";
	} while (run_command(cin, cout));
}

bool Game::run_command(istream& in, ostream& out) {
	Commands::Command command = next_command(in);

	switch (command) {
		case Commands::WALK:
			walk(in, out);
			break;
		case Commands::QUIT:
			return false;
		default:
			out << "Invalid command." << endl;
	}

	return true;
}

Commands::Command Game::next_command(istream& in) {	
	string command_raw;
	in >> command_raw;

	transform(command_raw.begin(), command_raw.end(), command_raw.begin(), ::tolower);


	Commands::Command command;
	if (!try_get_command(command_raw, command)) {
		command = Commands::INVALID;
	}

	return command;
}

void Game::walk(istream& in, ostream& out) {
	Commands::Command command = next_command(in);

	switch (command) {
		case Commands::NORTH:
		case Commands::SOUTH:
		case Commands::EAST:
		case Commands::WEST:
			out << "walking in some direction" << endl;
			break;
		default:
			out << "You can only walk *north*, *south*, *west* and *east*." << endl;
	}
}

bool Game::try_get_command(string str, Commands::Command& command) {
	map<string, Commands::Command>::iterator it;

	it = string_command.find(str);
	if (it == string_command.end()) return false;

	command = string_command[str];
	
	return true;
}




