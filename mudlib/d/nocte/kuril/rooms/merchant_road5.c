#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_dock_mob()) {
		add_action("no_exit", "east");
	}
	if(this_player()->chk_my_mob()) {
		if(!query_open("door")) {
			add_action("no_exit", "south");
		}
	}
}

void reset() {
	::reset();
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
		}
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
}

void create(){
	::create();
	seteuid(getuid());
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n   @--0\n   | \n   0\nMerchant Road");
	set("long",
		"The Lower Ward of Kuril is filled with the castouts and "
		"'undesireables' of Kuril.  During the day, the watchmen keep "
		"the peace in the Lower Ward."
		"  But this is not so during the night.  For even "
		"the watchmen return to the Upper Ward for their own "
		"safety.  So the south you can see a small fish market while."
		"  You quickly make a mental note to be very careful next time "
		"you are in the area at night." 
		"  To the east you can see a large temple structure.\n   0\n   | \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		({"fish market", "market"}): "The fish market is to the " +
			"south.",
		"denizens": "One growls at you in warning to mind your " +
			"own business while you're in here.",
		({"alley cats", "cats"}): "MEOW!!!",
		"school": "Dark storm clouds swirl about the towers.  "
			"Sometime is going on up there...but are you prepared "
			"to find out?"
	]) );
	set_exits( ([
		"north": ROOMS+"merchant_road4",
		"east": ROOMS+"merchant_road6",
		"south": ROOMS+"fish_market"
	]) );
	set_door("door", ROOMS+"fish_market.c", "south",
		"kuril fish market key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "06:00:00");
	set_close_function("close_door", "17:00:00");
}

void open_door() {
	call_other(ROOMS+"fish_market.c", "open_door");
}

void close_door() {
	call_other(ROOMS+"fish_market.c", "close_door");
}

int no_exit() {
	return 1;
}
