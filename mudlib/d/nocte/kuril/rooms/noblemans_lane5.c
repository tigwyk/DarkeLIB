#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("read_writing", "read");
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@   \n     \n    \nNobleman's Lane");
	set("long",
		"A large tavern can be seen immediately to the east.  Mutli-"
		"coloured windows cast shades of colour onto the lane.  "
		"Citizens go about their business--which is most likely "
		"something you do not want to know about.  Not known for "
		"its virtuousness, Kuril is still the home to many who will "
		"go to any means to make a fortune or carve a piece of power "
		"for themselves.\n   0\n   | \n0--@   \n     \n    \n"
	);
	set_items( ([
		"tavern": "Peering through the windows, you can see many "
			"tables full of customers, food, and bottles of "
			"liquor.",
		"windows": "Such exquisite glasswork must be very expensive.",
		"lane": "You are standing upon it.  The lane continues to the "
			"north and west.",
	]) );
	set_exits( ([
		"north": ROOMS+"noblemans_lane6",
		"west": ROOMS+"noblemans_lane4",
	]) );
}

int no_exit() {
	return 1;
}
