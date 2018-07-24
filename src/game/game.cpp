#include <istream>
#include <iostream>
#include <map>
#include <iterator>
#include "command.h"
#include "game.h"

using namespace std;

Commands::Command Game::get_command(istream& in) {	
	map<string, Commands::Command> commMap;

	commMap.insert(pair<string, Commands::Command> 
			("WALK", Commands::WALK));
	commMap.insert(pair<string, Commands::Command> 
			("INVENTORY", Commands::INVENTORY));
	commMap.insert(pair<string, Commands::Command> 
			("ARMOR", Commands::ARMOR));
	commMap.insert(pair<string, Commands::Command> 
			("WEAPON", Commands::WEAPON));
	commMap.insert(pair<string, Commands::Command> 
			("INFO", Commands::INFO));
	commMap.insert(pair<string, Commands::Command> 
			("EQUIP", Commands::EQUIP));
	commMap.insert(pair<string, Commands::Command> 
			("PICK_UP", Commands::PICK_UP));
	commMap.insert(pair<string, Commands::Command> 
			("DROP", Commands::DROP));
	
	string input;
	cout << "Enter a command: ";
	in >> input;	
	
	if (commMap.find(input) != commMap.end()) {
		cout << "The command you entered was: " 
		     << commMap.find(input)->second << endl;
		return commMap.find(input)->second;	
	} else {
		cout << "Invalid command";
		return Commands::INVALID;
	}
}
