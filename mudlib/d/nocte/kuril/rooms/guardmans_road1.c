#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
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
	set("short", "   0\n   | \n   @   \n   | \n   0\nGuardman's Road");
	set("long",
		"Far to the north is the end of Guardman's Road.  Strange "
		"that you can see no gate.  How on earth do they maintain "
		"adequate security in this city?  To the east you can see "
		"the city bakery.  Directly above you is a building supported "
		"by the surrounding structures.  To the south you can see "
		"what appears to be a large hole in the underpart of the "
		"supported building.\n   0\n   | \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"bakery": "You can only imagine what delicious goods must be "
			"sold there...then you notice the drool on your chin.",
		"building": "Many of the buildings in Kuril are multistoried "
			"in order to save space.",
		"hole": "You are unable to make out any details from this "
			"distance."
	]) );
	set_exits( ([
		"north": ROOMS+"guardmans_road5",
		"south": ROOMS+"guardmans_road2"
	]) );
}
