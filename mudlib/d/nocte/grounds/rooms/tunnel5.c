#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", -3);
	set_property("no castle", 1);
	set("short", "Inside the Tunnel");
	set("long",@ext
		Having past by the stalactite you can see from behind that a 
		doorway has been carved into the rear of it.  Unfortunately, 
		the only way in is fifty feet in the air....
		  The cave takes a bend to the west.
    0   
    |   
 0--@	
ext);
	set_listen("default", "You hear some crunching sounds to the west.");
	set_items( ([
		"stalactite": "As you take a closer look you see that it has windows carved into its side...wonder what's in there."
	]) );
	set_exits( ([
		"west": ROOMS+"tunnel6.c",
		"north": ROOMS+"tunnel4.c"
	]) );
}

void reset() {
	::reset();
	if(!present("_skeleton5"))
		new(MON+"skeleton5.c")->
		move(this_object());
	if(!present("_skeleton6"))
		new(MON+"skeleton6.c")->
		move(this_object());
}
