#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", -3);
	set_property("no castle", 1);
	set("short", "End of the Tunnel");
	set("long",
		"In the darkest recesses of this cave, the previous inhabitants "
		"buried their dead.  But their practices in the dark arts led "
		"to some experimentation into the art of necromancy....  "
		"Something begins to move right behind you."
	);
	set_listen("default", "You hear an unearthly scream reverberate against the cave walls as if they were some type of coffin....");
	set_exits( ([
		"east": ROOMS+"tunnel5.c"
	]) );
}

void reset() {
	::reset();
	if(!present("ghoul"))
		new(MON+"ghoul.c")->
		move(this_object());
}
