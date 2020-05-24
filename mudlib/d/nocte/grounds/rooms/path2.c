#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "Mouth of the Canyon");
	set("long",@ext
		Directly to the east is a large open area caused by 
		erosion upon the canyon walls.  You can make out 
		all manners of weapons and armor scattered upon the 
		ground.  Unfortunately it is all rusted and burned.

 0--@--0	
ext);
	set_listen("default", "Your voice bounces back and forth as you hum a hiking tune.");
	set_items( ([
		"walls":  "Black marks scar the walls from top to bottom.",
		"weapons":  "Swords, spear tips, maces, and some of unknown or ancient design.",
		"armor":  "The suits of armor are blackened and charred.  Only some of the sturdier metallic armors remain."
	]) );
	set_exits( ([
		"west": ROOMS+"path1.c",
		"east": ROOMS+"canyon1.c"
	]) );
}
