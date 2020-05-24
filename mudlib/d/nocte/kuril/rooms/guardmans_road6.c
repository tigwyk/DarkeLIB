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
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
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
	set("short", "    \n     \n   @   \n   | \n   0\nNorth City Gateway");
	set("long",
		"Just like those ancient city builders to construct another "
		"road that leads nowhere.  Except for that large gapping hole "
		"in the ground, you can not imagine why this part of the "
		"road was ever built.  On closer examination you notice "
		"that the hole is surrounded by runes.  "
		"Surrounding you is a shear drop to "
		"an untimely death.  Below you is a large river, pouring "
		"vast quantities of water into the ocean.\n    \n     \n   @   \n   | \n   0\n "
	);
	set_items( ([
		"road": "It continues southward passing right next to the "
			"large black structure in the distance.",
		"hole": "On closer examination you can see that it is "
			"some type of tube, magical symbols line the interior "
			"of the tube.  Surrounding the hole are four "
			"hemispherical holes.",
		"holes": "They are located at equidistant points around "
			"the mouth of the tube."
	]) );
	set_exits( ([
		"south": ROOMS+"guardmans_road5",
		"down": ROOMS+"ntube1"
	]) );
	set_invis_exits( ({ "down" }) );
}

int no_exit() {
	return 1;
}
