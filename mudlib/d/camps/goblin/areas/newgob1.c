#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "   0\n   | \n   @   \n   | \n   0\nA pebble road.");
	set("long", "This road has been used quite frequently as you can see the pebbles are very small in size due to erosion.  In front of you, you can see a settlement of some sort.\n   0\n   | \n   @   \n   | \n   0\n");
	add_exit("/d/damned/virtual/room_9_7.world","south");
	add_exit(ROOMS+"newgob2", "north");
}
