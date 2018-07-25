#pragma once

#include <iostream>
#include "area.h"

class Map {
public:
	Map(unsigned int length);
	~Map();

	void print(std::ostream& out);

	void spawn(Character* character, unsigned int x, unsigned int y);
	void find_first_free(unsigned int& x, unsigned int& y);
	bool find_random_free(unsigned int& x, unsigned int& y);


private:
	void generate();

	unsigned int length;
	Area*** grid;

	void add_wall_horizontal(unsigned int from, unsigned int to, unsigned int row);
	void add_wall_vertical(unsigned int from, unsigned int to, unsigned int col);
};
