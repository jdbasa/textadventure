#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <climits>

#include "map.h"

#include <iostream>

using namespace std;

Map::Map(unsigned int length) : length(length) {
	generate();
}

Map::~Map() {
	for (unsigned int i = 0; i < length; i++) {
		for (unsigned int j = 0; j < length; j++) {
			delete grid[i][j];
		}
		delete[] grid[i];
	}

	delete[] grid;
}

void Map::print(ostream& out) {
	for (unsigned int i = 0; i < length + 2; i++) {
		for (unsigned int j = 0; j < length + 2; j++) {
			char c = '.';
			if (i == 0 || i == length + 1) c = '-';
			else if (j == 0 || j == length + 1) c = '|';
			else if (grid[i-1][j-1]) {
				if (grid[i-1][j-1]->initialized()) {
					c = '0' + grid[i-1][j-1]->get_level();
				} else {
					c = 'o';
				}
			}
			out << c;
		}

		out << endl;
	}
}

void Map::spawn(Character* character, unsigned int x, unsigned int y) {
	unsigned int max_distance = 0;

	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 2; j++) {
			unsigned int temp = sqrt(
				(length * i - x) * (length * i - x) +
				(length * j - y) * (length * j - y));

			if (temp < max_distance) continue;

			max_distance = temp;
		}
	}

	for (unsigned int i = 0; i < length; i++) {
		for (unsigned int j = 0; j < length; j++) {
			if (!grid[i][j]) {
				continue;
			}
			unsigned int distance = sqrt(
				(i - x) * (i - x) +
				(j - y) * (j - y));

			grid[i][j]->generate((distance * 9) / max_distance);
			
		}
	}
}

void Map::find_first_free(unsigned int& x, unsigned int& y) {
	for (unsigned int i = 0; i < length; i++) {
		for (unsigned int j = 0; j < length; j++) {
			if (!grid[i][j]) continue;
			x = i;
			y = j;
			return;
		}
	}
}

bool Map::find_random_free(unsigned int& x, unsigned int& y) {
	for (unsigned int i = 0; i < 10000; i++) {
		x = rand() % length;
		y = rand() % length;

		if (!grid[x][y]) continue;

		return true;
	}

	return false;
}

void Map::generate() {
	grid = new Area**[length];
	for (unsigned int i = 0; i < length; i++) {
		grid[i] = new Area*[length];
		for (unsigned int j = 0; j < length; j++) {
			grid[i][j] = 0;
		}
	}

	srand(time(0));

	add_wall_horizontal(0, length, rand() % length);
}

void Map::add_wall_horizontal(unsigned int from, unsigned int to, unsigned int row) {
	for (unsigned int i = from; i < to; i++) {
		grid[i][row] = new Area();
	}

	if (row > from) {
		add_wall_vertical(from, row, from + rand() % (row - from));
	}

	if (to > row + 1) {
		add_wall_vertical(row + 1, to, row + 1 + rand() % (to - (row + 1)));
	}
}

void Map::add_wall_vertical(unsigned int from, unsigned int to, unsigned int col) {
	for (unsigned int i = from; i < to; i++) {
		grid[col][i] = new Area();
	}

	if (col > from) {
		add_wall_horizontal(from, col, from + rand() % (col - from));
	}

	if (to > col + 1) {
		add_wall_horizontal(col + 1, to, col + 1 + rand() % (to - (col + 1)));
	}
}






