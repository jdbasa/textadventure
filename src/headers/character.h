class Character {
public:
	int get_level();

	int get_health();
	int deal(int damage);
	int gain(int heal);

	int get_magic();
	bool consume(int mana);
	int regain(int mana);
private:
	int level;

	int max_health;
	int health;

	int max_magic;
	int magic;
};
