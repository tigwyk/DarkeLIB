// /wizards/excelsior/rooms/level3/road7
// Excelsior 7/2/96

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if(!present("tinker"))
		new("/wizards/excelsior/mon/tinker")->move(this_object());
}

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set("short","By an interesting shop");
	set("long","You are at the shop of a tinker- for lack of a better "+
		"word. He appears to deal in almost all things, as is apparent "+
		"from all the knicknacks and various junk he has hanging from his stand. "+
		"You could 'say shopkeeper, help' for assistance. The market "+
		"continues to the west and ends to the east.");
	set_items((["market":"It seems to be ending, as the stands "+
			"are becoming farther and farther apart.",
		({"knicknacks","junk"}):"There may be a few things to interest you.",
		"stand":"It is very disorganized."]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/road8",
		"west":"/wizards/excelsior/rooms/level3/road6"]));
	reset();
}
