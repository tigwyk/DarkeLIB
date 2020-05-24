#include <std.h>
#include "nevin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "East Canyon Wall");
	set("long",@ext
		A bunch of what appears to be scavengers are here 
		mucking around in the dirt and looting anything they can 
		find from the remains of the long dead.
    0   
    |   
 0--@
    |
    0	
ext);
	set_items( ([
		"scavengers":  "From the looks of them they appear to be bandits...not very good bandits though if they have to resort to scavenging from the dead.",
		"remains":  "Remains of the dead cover the canyon floor...most of the skeletons have been picked clean already."
	]) );
	set_exits( ([
		"north": ROOMS+"canyon8.c",
		"south": ROOMS+"canyon6.c",
		"west": ROOMS+"canyon4.c"
	]) );
}
