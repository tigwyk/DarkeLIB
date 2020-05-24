#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
		new(MON+"wm_fighter")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("ghost")) {
			new(MON+"ghost")->move(TO);
			new(MON+"ghost")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@   \n    \n   \nNobleman's Lane");
	set("long",
		"Far below you a waterfall pours its waters into two rivers.  "
		"The two rivers pour "
		"their waters into the sea.  Nestled in this embrace is the "
		"City of Kuril.  Evidence of the city's original inhabitants "
		"can be found everywhere.  But from this vantage point it is "
		"easy to see why they came here.  Perched upon an outcropping "
		"of rock, with water in all directions, the elves who came "
		"here found something that they believed was special.  Far to "
		"the east you can see billowing clouds rising from the earth.  "
		"A dull red glow highlights the clouds as they climb skyward.  "
		"An arch sits at the very end of the road upon which you have "
		"been traveling.  It's graceful designs and delicate carvings "
		"mark it as elven in origin.  It seems like a very strange "
		"place to place an arch, for if you tried to walk through it "
		"you would fall to your peril to the rivers below.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		({"river", "rivers"}): "The curl around the city and flow into "
			"the ocean.",
		"waterfall": "Below you to the east, a river ends in a "
			"waterfall.  The waters pour around Kuril in two "
			"rivers.",
		"city": "As you turn around to peer at the city, you can see "
			"the city docks along the ocean.",
		({"cloud", "clouds"}): "Something is producing large amounts "
			"of steam on the other side of the island.",
		"glow": "The glowing is so intense it can even be seen during "
			"the day."
	]) );
	set_exits( ([
		"west": ROOMS+"noblemans_lane7"
	]) );
	set_listen("default", "You hear the sound of roaring water.");
	new(MISC+"arch_nl8")->
		move(this_object());
}
