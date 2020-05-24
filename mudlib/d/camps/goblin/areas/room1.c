#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set("short", "    \n   u \n0--@   \n   d \n   0\nA secret passage");
	set("long", "A secret passage with many exits.\n    \n   u \n0--@   \n   d \n   0\n");

	add_exit("cave3", "south");
	add_exit("goblin4", "west");
	add_exit("idolroom", "up");
	add_exit("room2", "down");
}

void reset() {
	::reset();
	if(!present("torch"))
new("/std/obj/torch.c")->move(this_object());
	}

