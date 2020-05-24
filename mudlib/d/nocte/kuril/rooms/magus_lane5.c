#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "down");
	}
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		if(random(3) == 0) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("ghost")) { new(MON+"ghost")->move(TO); }
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @   \n     \n    \nSouth City Gate");
	set("long",
		"The burnt remains of a bridge that once crossed the ravine "
		"and river below are here.  They mark the desperate measures "
		"the last defenders of this city took to prevent the tide evil "
		"from capturing this city.  Unfortunately, their efforts did "
		"not succeed.  A large hole in the ground creates a haunting "
		"sound as the ocean breeze blows across it.  Runes of some "
		"sort form a ring around the hole.\n   0\n   | \n   @   \n     \n    \n"
	);
	set_items( ([
		"ravine": "Tall ravine walls now defend this city from "
			"intrusion to the south.",
		"walls": "Being almost perfectly vertical, it is a long "
			"drop to the river below.",
		"hole": "Peering into the hole, you are unable to see how "
			"far it goes.",
		"runes": "They form a ring around the hole.  You notice that "
			"there are four pits spaced equidistantly around the "
			"large hole.",
		"pits": "The are around the size of your fist.  It appears "
			"that an sphere could fit perfectly into each of them."
	]) );
	set_exits( ([
		"north": ROOMS+"magus_lane4",
		"down": ROOMS+"stube1"
	]) );
	set_invis_exits( ({ "down" }) );
	new(MISC+"bridge")->
		move(this_object());
}

int no_exit() {
	return 1;
}
