// /wizards/excelsior/rooms/street2
// around some shops

#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("light",1);
	set_property("indoors",0);
	set("short","By some shops");
	set("long","You are in a small alcove off of town square. To your northwest "+
		"is a grocery market, and to your northeast is some sort of magic shop. "+
		"They are both worth checking out. To your southeast is town square.");
	set_items( (["magic shop":"Northeast. Worth a look inside.",
		"grocery market":"East. Check it out.",
		"alcove":"That's where ya are!",
		"town square":"The center of things." ]) );
	set_exits( (["northeast":"/wizards/excelsior/rooms/shops/magic_shop",
		"northwest":"/wizards/excelsior/rooms/shops/heal_shop",
		"southeast":"/wizards/excelsior/rooms/square"]));
}

