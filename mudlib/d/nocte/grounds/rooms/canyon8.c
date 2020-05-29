#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "North Canyon Wall");
	set("long",
		"Hmmm...more of those funny looking white plants.  They sure "
		"seem to grow really well in here.  Beyond the plants is "
		"what looks like the remains of a cave in."
	);
	set_items( ([
		"plants": "You notice some black dots around the white plants.",
		"dots": "As you get a closer look you realize that they are the hulks of dried out insects!  So that's what these plants eat.",
		"wall":  "There appears to a a gap in the fallen rocks",
		"gap":  "You would have to be really small to fit into it."
	]) );
	set_exits( ([
		"west": ROOMS+"canyon5.c",
		"south": ROOMS+"canyon7.c"
	]) );
}
