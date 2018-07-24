#include "items.h"
#include "rusted.h"

/*static*/ const Items Items::instance;

Items::Items() {
	items = new Item*[ITEM_COUNT];
	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		items[i] = create((ItemName)i);
	}
}

Item* Items::create(ItemName name) {
	switch (name) {
		case RUSTED_SWORD:
			return new RustedSword();
		case RUSTED_SHIELD:
			return new RustedShield();
		case RUSTED_HELMET:
			return new RustedHelmet();
		default:
			return 0;
	}
}

Item* Items::get(ItemName name) const {
	return items[name];
}

std::string Items::to_string(ItemName name) const {
	switch (name) {
		case RUSTED_SWORD:
			return "Rusted Sword";
		case RUSTED_SHIELD:
			return "Rusted Shield";
		default:
			return "No name";
	}
}

Items::~Items() {
	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		delete items[i];
		items[i] = 0;
	}

	delete[] items;
}
