#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		if(!query_open("door")) {
			add_action("no_exit", "north");
		}
	}
}

void reset() {
	::reset();
	if(query_night()) {
		if(!present("watchman")) {
			new(MON+"wm_fighter")->move(TO);
			new(MON+"wm_fighter")->move(TO);
			new(MON+"wm_fighter")->move(TO);
		}
	}
	if(!query_night()) {
		if(!present("watchman")) {
			new(MON+"wm_fighter")->move(TO);
		}
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
		new(MON+"kuril_cit")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n    \n   \n Nobleman's Lane");
	set("long",
		"Upon entering the heart of the Noble Ward you can see that "
		"this area of Kuril is well kept.  The streets have been "
		"cleaned and the buildings recently washed.  To the north "
		"you can see the city bakery.  "
		"A cool breeze blows in from the sea.  "
		"The cool air swirls around you bringing the scents of the "
		"ocean with it.  Ah, refreshing.  A building right above you "
		"shelters you from the elements.\n   0\n   | \n0--@--0\n    \n   \n "
	);
	set_items( ([
		"streets": "From the looks of things, this area is very "
			"wealthy...there must be a thieves guild in the city.",
		"building": "To the west you can see a hole on the bottom of "
			"the building that you are now passing under.",
		"buildings": "In order to save precious space, almost all "
			"of the city's buildings are multistory structures.",
		"bakery": (: call_other, this_object(), "look_bakery" :),
		"hole": "It looks fairly large...perhaps..."
	]) );
	set_exits( ([
		"north": ROOMS+"bakery",
		"east": ROOMS+"noblemans_lane2",
		"west": ROOMS+"guardmans_road2"
	]) );
	set_door("door", ROOMS+"bakery.c", "north",
		"kuril bakery key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "05:00:00");
	set_close_function("close_door", "15:00:00");
}

void look_bakery() {
	if(query_night() == 1) {
		write("The interior of the bakery is pitch dark.");
	}
	else {
		write("Customers have lined up by the dozens to purchase "
			"the delicious baked goods sold inside.");
	}
}

void open_door() {
	call_other(ROOMS+"bakery.c", "open_door");
}

void close_door() {
	call_other(ROOMS+"bakery.c", "close_door");
}

int no_exit() {
	return 1;
}
