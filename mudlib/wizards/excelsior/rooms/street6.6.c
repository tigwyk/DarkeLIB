// /wizards/excelsior/rooms/street6.6

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","At a road heading up");
	set("long","Here the road curves to the north and up. The steep slope "+
		"that it froms serves as a way for carts and other less agile things "+
		"to reach higher levels of the city. You wonder how high this city can "+
		"go.");
	set_items( (["road":"It leads up to the next level of the city.",
		"ramp":"Up it goes."]) );
	set_exits( (["east":"/wizards/excelsior/rooms/street6.5",
		"northup":"/wizards/excelsior/rooms/level3/road1" ]) );
}

