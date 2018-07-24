class Character;

struct Item {
	Item(int rarity, int speed);

	const int rarity;
	const int speed;
};

struct Weapon : Item {
	Weapon(int rarity, int speed, int attack, int consumption);

	const int attack;
	const int consumption;

	virtual void effect(Character* from) {}
};

struct Armor : Item {
	Armor(int rarity, int speed, int defence, int consumption);

	const int defence;
	const int consumption;
	virtual void passive(Character* from, int& incoming_damage) {}
};
