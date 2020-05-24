#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("read_sign", "read");
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("watchman")) {
		if(random(2) == 0) {
			new(MON+"wm_fighter")->move(TO);
		}
	}
	if(!present("citizen")) {
		if(random(2) == 0) {
			new(MON+"kuril_cit")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@--0\n   | \n   0\nNobleman's Lane");
	set("long",
		"Once glorious towers line the road as you walk past a large "
		"pub to the south.  Even from here you can see wealthy "
		"patrons sitting down for large meals followed by bottles upon "
		"bottles of wine.  "
		"Although the upper levels of the city's "
		"many towers have been allowed to fall into ruin, the lower "
		"levels are still occupied." 
		"  To the east you can see an arch at the end of the road.\n   \n    \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"towers": "Falling into ruin and decay, they are still used "
			"by the wealthy and powerful.  Why they have not "
			"repaired the towers is probably because of the "
			"fierce lightning storms that occur each night near "
			"the School of Necromancy....",
		"patrons": "A few look more than a little drunk.",
		({"bottles", "wine"}) : "Why don't you go in if you really "
			"want a taste.",
		"arch": "It appears to be just sitting at the end of the road."
	]) );
	set_exits( ([
		"east": ROOMS+"noblemans_lane8",
		"south": ROOMS+"raking_claw",
		"west": ROOMS+"noblemans_lane6"
	]) );
	set_door("door", ROOMS+"golden_beers", "south",
		"kuril golden beers key");
	set_open("door", 1);
	set_locked("door", 0);
}

int no_exit() {
	return 1;
}
