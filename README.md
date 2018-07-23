# Text Adventure

## Documentation
For any help use the `help` command.

### Characters

### Items
All characters are allowed to carry an unlimited number of items. In general, if an item is found, you can pick it up by using `pickup [item name]`.  
If you have an item in your inventory that you wish to drop, you can use `drop [item name]`.

You can see all non-weapon and non-armor items  in your inventory by using `inventory`.  
You can see all your armor items using `armor`.  
You can see all your weapon items using `weapons`.  
To see what you currently have equipped use `equipped`.  
To see information on any item in your inventory use `info [item name]`.  

#### Armor
All characters have armor, there are 6 armor slots for 6 item types:
* Head Gear
* Body Armor
* Right Glove
* Left Glove
* Legwear
* Boots

Characters can only have one equipped per armor slot. Therefore, not matter what type of configuration a character has, it can only have a maximum of 6 armor items equipped.

To equip armor, the command is: `equip [armor name]`.

Some armor has passive abilities or active abilities. Passive abilities require no user action, active abilities require an issuing of a command and most likely consumes magic.  
To use an active ability: `use [armor name]`.

Armor comes with defence.

### Weapons
All characters can have weapons, there are two types of weapons: Attacking Weapons and Defensive Weapons.

An Attacking Weapon is something like a sword or knife.  
A Defensive Weapon is something like sheild.

A character may hold a maximum of two weapons. Some weapons require the usage of two hands. You may use AWs or DWs for either attacking or defending, but an AW will usually be worse than DWs at guarding and DWs will be worse at attacking than AWs.

To equip weapons: `equip [weapon_name]`. To attack: `attack [left|right]`. To guard: `guard [left|right]`.

Weapons may also have passive and active abilities. The rules to those apply like the armor.


