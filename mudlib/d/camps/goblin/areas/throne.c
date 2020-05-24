#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "    \n     \n   @   \n   | \n   0\nThe room of the mighty Grom");
	set("long", "This room is quite a fabulous one indeed, there is gold pouring from every edge of the room, with beautiful gems randomly droped.  In the far back of the room there is a huge throne, made of bones and obsidian strewn together in a glorious heap.  On the throne sits Grom, Grom the paunch of Misty mountain.  The infamous goblin leader.\n    \n     \n   @   \n   | \n   0\n");
	set_items((["gold" : "The gold is everywhere in the room, it seems to be eminating from every oriface of this room."
]));
set_exits( ({(ROOMS+"grom")}), ({"south"}));

}

void reset() {
	::reset();
if(!present("grom"))
new(MON+"grom.c")->move(this_object());
}

