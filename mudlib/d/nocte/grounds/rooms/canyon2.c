#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "North Canyon Wall");
	set("long", @ext
		To the north is the North Canyon Wall.  A small trickle of 
		a stream has wound it's way down the canyon wall to fall 
		in a sprinkle here upon the canyon floor.
    @--0
    |
    0	
ext);
	set_listen("default", "You can hear water pitter patting upon the hard canyon rocks.");
	set_items( ([
		"wall":  "A small stream pours down the canyon wall.",
		"stream":  "It appears that this stream is the only source of water down in the canyon."
	]) );
	set_exits( ([
		"south": ROOMS+"canyon1.c",
		"east": ROOMS+"canyon5.c"
	]) );
}
