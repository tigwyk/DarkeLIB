#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		if(!query_open("door")) {
			add_action("no_exit", "west");
		}
	}
	if(TP->chk_temple_mob()) { add_action("no_exit", "west"); }
}

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
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
	set("short", "   \n    \n0--@--0\n   | \n   0\nThieves' Court");
	set("long",
		"You are standing near the end of Thieves' Court.  To the west "
		"is the butcher shop while to the south you can see an arch of "
		"some type.  As far as you can tell, to the south is also "
		"the end of the court.\n   \n    \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"store": "You can hardly see inside because of the boards on "
			"the windows",
		"sign": "It reads: FOR SALE (inquire when player owned shops "
			"are added)"
	]) );
	set_exits( ([
		"east": ROOMS+"thieves_court2",
		"south": ROOMS+"thieves_court4",
		"west": ROOMS+"butcher_shop"
	]) );
	set_door("door", ROOMS+"butcher_shop.c", "west", 
		"kuril butcher shop key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
}

void open_door() {
	call_other(ROOMS+"butcher_shop.c", "open_door");
}

void close_door() {
	call_other(ROOMS+"butcher_shop.c", "close_door");
}

int no_exit() {
	return 1;
}
