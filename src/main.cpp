#include <iostream>
#include "map.h"

using namespace std;

int main(int args, char** cargs) {
	Map map(10);
	map.print(cout);

	unsigned int x;
	unsigned int y;
	if (map.find_random_free(x, y)) {
		map.spawn(0, x, y);
		map.print(cout);
	}
	return 0;
}
