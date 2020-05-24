#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "Canyon Interior");
	set("long", @ext
		As you enter the canyon you can see the layers of rock 
		that the canyon was cut from.  Where no plants could 
		normally grow, or rarely grow, you find that the canyon 
		is teeming with plant and some animal life.
    0   
    |   
 0--@--0	
ext);
	set_listen("default", "The wind creates a howling sound as it cuts across the top of the canyon.");
	set_items( ([
		"layers": "It must have taken millions of years to form this vast canyon.",
		"rock": "Yes, nice hard rocks...good for throwing.",
		"animals": "A few mice scurry away as you pass by.",
		"plants": "Although most of the plants are green, some of are almost white in color.  You wonder how they could survive here."
	]) );
	set_exits( ([
		"west": ROOMS+"path2.c",
		"east": ROOMS+"canyon4.c",
		"north": ROOMS+"canyon2.c"
	]) );
}
