// /wizards/excelsior/rooms/street6.5

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",2);
	set_property("indoors",0);
	set("short","A intersection");
	set("long","You have come to a intersction of roads. The main road to "+
		"the other parts of the city turns to the west here, while to the "+
		"east is a dark alley way. You would not want to travel down this "+
		"alley at night. Most people travel from the north to west or vise "+
		"versa. You only see a few criminal looking types head east.");
	set_items( (["alley":"It is dark and probably rat infested.",
		"people":"Very few go east.",
		"criminals":"You prejudging bastard!"]) );
	set_exits( (["north":"/wizards/excelsior/rooms/street6.4",
		"east":"/wizards/excelsior/rooms/gnome_farms/alley1",
		"west":"/wizards/excelsior/rooms/street6.6" ]) );
}
