class Character;

class Item {
	virtual int rarity() = 0;
};

class Weapon : Item {
	// from Item
	virtual int rarity() = 0;

	virtual int attack() = 0;
	virtual int consumption() = 0;
	virtual int effect(Character* from) = 0;
};

class Armor : Item {
	// from Item
	virtual int rarity() = 0;
	
	virtual int defence() = 0;
	virtual void passive(Character* from, int& incoming_damage) = 0;
};
