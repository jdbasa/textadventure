#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <sstream>
#include "command.h"
#include "game.h"

using namespace std;

Commands::Command Game::get_command(istream& in) {	
	map<string, Commands::Command> comm_map;

	comm_map.insert(pair<string, Commands::Command> 
			("WALK", Commands::WALK));
	comm_map.insert(pair<string, Commands::Command> 
			("INVENTORY", Commands::INVENTORY));
	comm_map.insert(pair<string, Commands::Command> 
			("ARMOR", Commands::ARMOR));
	comm_map.insert(pair<string, Commands::Command> 
			("WEAPON", Commands::WEAPON));
	comm_map.insert(pair<string, Commands::Command> 
			("INFO", Commands::INFO));
	comm_map.insert(pair<string, Commands::Command> 
			("EQUIP", Commands::EQUIP));
	comm_map.insert(pair<string, Commands::Command> 
			("PICK_UP", Commands::PICK_UP));
	comm_map.insert(pair<string, Commands::Command> 
			("DROP", Commands::DROP));
	
	string command;
	string input_list[4];
	cout << "Enter a command: ";
	getline(in, command);
	
	stringstream str(command);	
	string buf;
	
	int i = 0;
	while (str >> buf) {
		transform(buf.begin(), buf.end(), buf.begin(), ::toupper);
		input_list[i] = buf;
		++i;	
	}

	string comm = input_list[0];
	
	cout << "The input command is: " << comm << endl;
	cout << "The input param(s) is/are: ";
	for (unsigned int i = 1; i < sizeof(input_list) / 
			sizeof(input_list[1]); ++i) {
		cout << input_list[i] << " ";
	}
	cout << endl;	
	if (comm_map.find(comm) != comm_map.end()) {
		cout << "The command you entered was: " 
		     << comm_map.find(comm)->second << endl;
		return comm_map.find(comm)->second;	
	} else {
		cout << "Invalid command" << endl;
		return Commands::INVALID;
	}
}
