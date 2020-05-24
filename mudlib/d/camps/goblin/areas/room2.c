#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set("short", "   0\n   u \n   @--0\n   | \n   0\nA secret passage");
	set("long", "A deeper secret passage in the goblin settlement, there seems something strange with the room, maybe in the walls or floor.\n   0\n   u \n   @--0\n   | \n   0\n");
	add_exit("room1", "up");
	add_exit("cave4", "east");
	add_exit("grom", "north");
	add_exit("room3", "down");
	add_invis_exit("down");
	set_items( ([ "floor" : "The floor seems somehow magically enchanted, it almost feels like you can go down.",
])
);
	add_exit("goblin3", "south");

new(MON+"crawler.c")->move(this_object());
new(ITEM+"worldmap.c")->move(this_object());
}

