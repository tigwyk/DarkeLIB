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
		As a child you remember all kinds of horror stories told 
		about caves like these...orcs, trolls, giants, and sometimes 
		even drow....

 0--@--0	
ext);
	set_listen("default", "You wonder if everyone can hear your heart pounding like mad...or if only  you can.");
	set_exits( ([
		"west": ROOMS+"tunnel1.c",
		"east": ROOMS+"tunnel3.c"
	]) );
}
