#include <istream>

class Game {
public:
	Character player;
	void update();

	Command get_command(istream& in);
};
