#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
	}
	if(!present("zombie")) {
		if(random(2) == 0) {
			new(MON+"ku_zombie")->move(TO);
		}
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

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "    \n     \n   @   \n   | \n   0\nMagus Lane");
	set("long",
		"You are at the northern most part of Magus Lane.  A collapsed "
		"bridge is all that remains of a bridge that once extended "
		"over the ravine and river below.  An archway marks the very "
		"end of the lane.  Far below you is a large river flowing "
		"swiftly past the city on its way to the ocean.  Ravine walls "
		"surround the river in walls on stone.  To the south you can "
		"see Magus Lane extending all the way past the School of "
		"Necromancy.\n    \n     \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"ravine": "Cut by the river itself over millenia, the ravine "
			"walls are almost perfectly vertical.",
		"walls": "You notice that they widen near the base of the "
			"ravine.  It appears that the rocks composing the "
			"base of the ravine has been washed away faster than "
			"the previous layers.",
		"layers": "You can see the different layers of the ravine "
			"by looking at the various colours of the lines "
			"running horizontally along the ravine walls.",
		"river": "Rivers have always been an efficient method of "
			"transportation.  You wonder why Kuril has "
			"no access to the river below.",
		"ocean": "To the western horizon, you can just make out "
			"land far to the west.",
		"stone": "Eaten away by time and water, the deep ravine "
			"has created a natural defense for the city.",
		"school": "It is located in that tall multitowered structure "
			"far to the south"
	]) );
	set_exits( ([
		"south": ROOMS+"fountain_square1"
	]) );
	new(MISC+"arch_ml1")->
		move(this_object());
	new(MISC+"bridge")->
		move(this_object());
}
