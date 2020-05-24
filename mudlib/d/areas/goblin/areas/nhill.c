#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 2);
	set("short", " 0 0 0\n  *|/ \n   @   \n   |  \n   0\nA room a cave, with 3 exits.");
set_long("This is a room where goblins eat sleep and drink. The room itself is covered with wood chips from all the bashing that the goblins have done.\n0 0 0\n  *|/ \n   @   \n   |  \n   0\n");
set_exits( ({(ROOMS+"settlement2"), (ROOMS+"shamanroom"), (ROOMS+"hallway"), (ROOMS+"grom")}), ({"south", "northwest", "north", "northeast"}));
}
