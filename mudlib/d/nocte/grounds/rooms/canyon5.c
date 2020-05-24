#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "North Canyon Wall");
	set("long",@ext
		The canyon wall continues to the west and to the east.  
		On the ground you notice some very large white plants.  
		Is that the wind or are those plants moving?

 0--@--0
    |
    0	
ext);
	set_listen("default", "You hear only the wind and your heavy breathing...strange that there are no animals here....");
	set_items( ([
		"plants": "You wonder what on earth these plants could eat.",
		"wall":  "Same ole wall...you must like staring at walls."
	]) );
	set_exits( ([
		"west": ROOMS+"canyon2.c",
		"east": ROOMS+"canyon8.c",
		"south": ROOMS+"canyon4.c"
	]) );
}

