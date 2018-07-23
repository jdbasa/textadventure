# Text Adventure

## Documentation
For any help use the `help` command.

### Characters

#### Items
All characters are allowed to carry an unlimited number of items. In general, if an item is found, you can pick it up by using `pickup [item name]`.  
If you have an item in your inventory that you wish to drop, you can use `drop [item name]`.

You can see all non-weapon and non-armor items  in your inventory by using `inventory`.  
You can see all your armor items using `armor`.  
You can see all your weapon items using `weapons`.  
To see what you currently have equipped use `equipped`.  
To see information on any item in your inventory use `info [item name]`.  
To use an item in general: `use [item name]`. Some items can't be used. Any item can be used at any time, however, items have a usage speed if in combat.

Items can have various uses ranging from increasing your maximum health to casting a one-time fire blast.

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

#### Weapons
All characters can have weapons, there are two types of weapons: Offensive Weapons and Defensive Weapons.

An Offensive Weapon is something like a sword or knife.  
A Defensive Weapon is something like sheild.

A character may hold a maximum of two weapons. Some weapons require the usage of two hands. You may use OWs or DWs for either attacking or guarding, but an OW will usually be worse than DWs at guarding and DWs will be worse at attacking than OWs.

To equip weapons: `equip [weapon name]`. To attack: `attack [left|right]`. To guard: `guard [left|right]`. 

Weapons may also have passive and active abilities. The rules to those apply like the armor.

Weapons also have a speed, which is an integer that has a minimum of 0. It determines how much 'time' a weapon needs to attack - more on this later.


#### Spells
Spells are acquired by using scrolls or through an equipment passive ability.

To learn a spell use command on the scroll `use [scroll item name]`.  
To cast a spell, use `cast [spell name]`.  
To see all learned spells use `spells`.  
All spells consume magic.


### Combat


#### Time Units
Combat works different in this game than in other games.

Every action has a speed in 'time' units. You don't need to care about how long are time units, but if it helps, consider one time unit to one second.  
When a character does an action, it takes the corresponding time units for it to be realized. The next action is allowed to take place as soon as one is realized.

This is explained better with an example.  
You attack with a weapon with speed 3 and a goblin attacks you with a weapon of speed 5.  
First, you will notice that you hit the goblin first since 3 time units have passed. At this point, you can attack again, but this time, the goblin would have attacked you since a total of 5 time units would have passed before your next attack is realized. At 3 time units, you attack hits, at 5 time units, the goblin attack hits, at 6 time units, you attack hits again.

Items also have time units, but they're usually short, which the exception of learning spells.

Guard speed is time to put up your defenses.


#### Attacking
To attack, use `attack [left|right]`. Attack damage dealt to another character is that of damage dealt by the weapon minus the defense the other character has.  


#### Guarding
To guard, use `guard [left|right]`. If a character is already guarding while there is an attack to them, the character will block more damage than usual with possible side effects.


#### Item Usage
To use an item during combat is the same as using an item outside of combat: `use [item name]`.


### Exploration
The point of the game is to kill the dragon that terrorizes the people of the land. 

To see the world map use `map`. Use the legend on the map to orientate yourself.

Every grid space on the map is considered an area. To look around use the `inspect` command. This gives you a list of items you are able to pick up. Using `inspect [item name]` gives you information on the item much like how `info [item name]` would. The different is that `info` is used for inventory items and `inspect` is used for items not yet picked up.

To move into a new area you must walk to it using the `walk` command with a direction: `walk [north|south|east|west]`. Walking into a new area means potentially running into an enemy. You may run into many enemies.


### Stretch goals

* Party members
* Trading
* Story
* Talking to people
