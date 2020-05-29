#include <std.h>
#include <nevin.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", -1);
	set_property("no castle", 1);
	set("short", "Mouth of the Tunnel");
	set("long",
		"A creepy sensation goes up your spine as you realize that "
		"you are not alone in here....  The tunnel continues of into "
		"the darkness to the east."
	);
	set_listen("default", "The sound of your boots echoing down the tunnel tells everyone or anything inside that someone is approaching.");
	set_items( ([
		"spine":  "It looks a bit mushy there...you sure you don't want your mommy to hold your hand?"
	]) );
	set_exits( ([
		"west": ROOMS+"canyon6.c",
		"east": ROOMS+"tunnel2.c"
	]) );
}
