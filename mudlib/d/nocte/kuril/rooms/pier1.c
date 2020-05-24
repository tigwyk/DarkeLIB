#include <std.h>
#include "nevin.h"
inherit "/std/pier";

void init() {
	::init();
	if(query_night() == 1) { delayed_call("night_time", 1); }
	else { delayed_call("day time", 1); }
}

void reset() {
	int i;
	::reset();
	if(!query_night()) {
		if(!present("dockworker")) {
			for(i=0;i<=1;i++) {
				if(random(3) == 0) {
					new(MON+"dockworker")->move(TO);
				}
			}
		}
		if(!present("citizen")) { new(MON+"kuril_cit_lw")->move(TO); }
	}
	if(query_night()) {
		new(MON+"ku_wight")->move(TO);
		if(!present("ghost")) { new(MON+"ghost")->move(TO); }
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "City Pier");
	set("long",
		"Looking out onto the ocean, it is hard to believe that such "
		"a city could coexist right next to such natural beauty.  "
		"The necromancers could not have been the original founders of "
		"this place.  They are the masters of dead and decay--not "
		"creation and life.  Far in the distance you can see small "
		"boats making their daily fishing runs.  "
		"Some old barrels and "
		"crates litter the end of the pier.  To the east is a road "
		"and what appears to be a marketplace."
	);
	set("night long",
		"A thick mist fills the air making travel precarious through "
		"this area of the city.  You had better be careful you do not "
		"fall into the water.  Who knows what foul creatures reside in "
		"the swirling waters around the Island of Kuril."
	);
	set_items( ([
		"ocean": "Sure is a nice view, much different from the "
			"city to your back.",
		"crests": "You wonder if it's really true that sea foam "
			"is really the remains of dead mermaids.",
		({"barrels", "crates"}): "Refuse fills the barrels to the "
			"brim."
	]) );
	set_exits( ([
		"east": ROOMS+"merchant_road2"
	]) );
	set_smell("default", "The smells of the sea greet you as you step upon the pier.");
	set_listen("default", (: call_other, this_object(), "listen_default" :));
	set_max_fishing(10);
	set_chance(5);
	set_max_catch(10);
	set_fish( ([
		"tuna":1,
		"mackeral":2
	]) );
}

string listen_default() {
	if(query_night() == 1) {
		return "To the south you can hear bawdy laughter and singing.";
	}
	else {
		return "Sea gulls cry out as they circle in the air.";
	}
}
/*
void night_time() {
	add_item("ship", "On it's side are written the words: The Sea Hag  "  
		"It is not too far out, perhaps you could jump to it.");
	remove_item( ({"fishing boats", "boats"}) );
}

void day_time() {
	remove_item("ship");
	add_item( ({"fishing boats", "boats"}), "You can barely make out the "
		"fisherman slowly letting out their nets and then pulling them "
		"back in.");
}
*/
