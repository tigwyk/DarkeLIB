#include <std.h>
#include "nevin.h"
inherit ROOM;

void init() {
	::init();
	if(this_player()->chk_dock_mob()) {
		add_action("no_exit", "east");
	}
	if(this_player()->chk_mp_mob()) {
		add_action("no_exit", "south");
		add_action("no_exit", "west");
	}
}

void reset() {
	::reset();
	if(!query_night()) {
		if(!present("watchman")) {
			new(MON+"wm_fighter")->move(TO);
		}
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
		}
		if(!present("dockworker")) {
			new(MON+"dockworker")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nMerchant Road");
	set("long",
		"Being the waterside district of Kuril, you see a long "
		"pier to the west jutting out into the ocean.  Cracked, "
		"broken stones twist and shift under your feet.  Occasionally "
		"you step on something soft...you don't even want to know "
		"what that is.  It is along this road that the merchants and "
		"citizens of Kuril ply and purchase goods and services.  "
		"To the east is a marketplace while to the southeast is a "
		"large multistoried building.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
//		"pier": (: call_other, this_object(), "look_pier" :)
	]) );
	set_exits( ([
		"north": ROOMS+"merchant_road1",
		"east": ROOMS+"marketplace3",
		"south": ROOMS+"merchant_road3",
		"west": ROOMS+"pier1"
	]) );
}

int no_exit() {
	return 1;
}
