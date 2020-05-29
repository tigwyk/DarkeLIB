#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "Center of the Canyon");
	set("long",
		"You are standing in the center of the canyon.  It extends "
		"in every direction.  If only you could fly...you might be "
		"to check out what's on that ledge to the south."
	);
	set_items( ([
		"ledge":  "It placed very high on the canyon wall...what was that?  Did something just move up there?"
	]) );
	set_exits( ([
		"west": ROOMS+"canyon1.c",
		"east": ROOMS+"canyon7.c",
		"south": ROOMS+"canyon3.c",
		"north": ROOMS+"canyon5.c"
	]) );
}
