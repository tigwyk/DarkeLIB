#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", -3);
	set_property("no castle", 1);
	set("short", "Inside the Tunnel");
	set("long",
		"The cave begins to descend here.  You notice that the cave "
		"walls are covered with buildings.  The cave continues south "
		"past that large stalactite."
	);
	set_items( ([
		"stalactite":  "Wow, now that is one HUGE stalactite.  Hmm...if you look at it from the right angle it looks like a face.",
		"buildings": "They appear to be the ruins of an ancient civilization."
	]) );
	set_listen("default", "You hear the occasional drip of water.");
	set_exits( ([
		"north": ROOMS+"tunnel3.c",
		"south": ROOMS+"tunnel5.c"
	]) );
}

void reset() {
	::reset();
	if(!present("_skeleton4"))
		new(MON+"skeleton4.c")->
		move(this_object());
}
