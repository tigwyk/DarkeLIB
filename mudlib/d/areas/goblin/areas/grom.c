#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   | \n   @   \n  /  \n 0 \nA room with many weapons.");
	set_long("This room is one of true amazement, the weapons in this room are spectacular, some of them are antiques while some are right out of the weaponsmith.  All of the weapons are put on racks for people to see in awe.  You don't really want to touch these weapons as they seem somewhat magically stuck here.\n   0\n   | \n   @   \n  /  \n 0 \n");
	set_items(([
	"weapons" : "This is one of the most impressive looking display of weapons that you have seen, there are all types of weapons to be found, axes, swords, shields, everything.  Including an extremely rare flint lock pistol.  There seems to be a magical force keeeping the weapons in their racks so that no one can touch them."
]));
set_exits( ({(ROOMS+"throne"), (ROOMS+"hill")}), ({"north", "southwest"}));

	add_exit("room2", "south");
	add_invis_exit("south");
}

