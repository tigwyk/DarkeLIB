#include <std.h>
#include "nevin.h"

inherit "/std/pier";



void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		add_action("no_exit", "west");
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
		if(!present("dockworker")) {
			new(MON+"dockworker")->move(TO);
		}
		if(!present("sailor")) {
			new(MON+"sailor")->move(TO);
		}
		if(!present("fisherman")) {
			new(MON+"fisherman")->move(TO);
		}
	}   
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   \n    \nO  @--0\n   s \n    \nA city pier.");
	set("long",
		"You barely manage to keep your footing as you step on the "
		"slippery pier.  An ocean breeze fills your nose with fresh "
		"salty air.  Ah, truly a magnificent sight...then you turn "
		"around.  Nestled between two large rivers is the City of "
		"Kuril.  The city climbs upwards to a peak far in the "
		"distance.  Home of the Kurilian School of Necromancy, "
		"the most powerful necromantic organization in the known "
		"world, the dark blackened towers and crumbling faded walls "
		"are a dying testamony to the great civilization that "
		"existed here.  Even in their blackened twisted form you can "
		"instantly recognize the work of elven hands.  A cluster of "
		"towers to the east, reaching for the sky like a clawing fist, "
		"mark the location of the School of Necromancy.  To the east "
		"is a road and a tavern of sorts.\n   \n    \nO  @--0\n   s \n    \n" 
	);
	set_items( ([
	]) );
	set_exits( ([
		"east": ROOMS+"merchant_road4",
                "sea": "/d/damned/virtual/room_8_12.world",
                "out": "/d/damned/virtual/room_8_12.world"
	]) );
	set_smell("default", "The scent of the ocean fills the air.");
	set_listen("default", "Ocean waves spray up clouds of mist as they break upon the pier.");
	set_max_fishing(10);
	set_chance(5);
	set_max_catch(10);
	set_fish( ([
		"tuna":1,
		"makeral":2
	]) );
	call_out("load_shop_stores", 1);
}

int no_exit() { return 1; }

int query_water() { return 1; }

void load_shop_stores() {
	find_object_or_load(ROOMS+"butcher_shop_storage");
	find_object_or_load(ROOMS+"parchment_shop_storage");
	find_object_or_load(ROOMS+"fish_market_storage");
	find_object_or_load(ROOMS+"magic_shop_storage");
	find_object_or_load(ROOMS+"corpse_market_storage");
	find_object_or_load(ROOMS+"candle_shop_storage");
	find_object_or_load(ROOMS+"book_binder_storage");
	find_object_or_load(ROOMS+"general_store_storage");
	find_object_or_load(ROOMS+"bakery_storage");
	find_object_or_load(ROOMS+"alchemist_storage");
}
