#include "items.h"
#include "rusted.h"

/*static*/ const Items Items::instance;

Items::Items() {
	items = new Item*[ITEM_COUNT];
	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		items[i] = create((ItemType)i);
	}
}

Item* Items::create(ItemType name) {
	switch (name) {
		case RUSTED_SWORD:
			return new RustedSword();
		case RUSTED_SHIELD:
			return new RustedShield();
		default:
			return 0;
	}
}

Item* Items::get(ItemType name) const {
	return items[name];
}

Items::~Items() {
	for (unsigned int i = 0; i < ITEM_COUNT; i++) {
		delete items[i];
		items[i] = 0;
	}

	delete[] items;
}
