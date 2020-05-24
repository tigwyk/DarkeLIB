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
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
		//if(!present("merchant")) {
			//new(MON+"merchant1")->move(TO);
		//}
		//if(!present("cart")) {
			//new(MISC+"cart1")->move(TO);
		//}
		if(!present("watchman")) {
			new(MON+"mp_fighter")->move(TO);
			new(MON+"mp_fighter")->move(TO);
		}
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nMarketplace");
	set("long",
		"Being the center of the Kurilian trade economy, the "
		"marketplace is full of merchants and buyers during the "
		"daylight hours.  Merchants sell their goods all around you.  "
		"To the north is the corpse market while the marketplace "
		"continues to the east and south.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set("night long",
		"Now desolate, the marketplace of Kuril is quiet and empty.  "
		"Creatures stir about you in the darkness.  Cries in the night "
		"continue to remind you to keep alert.  A shop to the north "
		"is open for some reason.  Strange that this shop has remained "
		"open while all the others have long since closed.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"vendors": "They are very busy hangling over the values " +
			"of their goods.",
		"goods": "Cloth, spices, and even slaves can all be " +
			"be purchased in the Kurilian Marketplace."
	]) );
	set_exits( ([
		"north": ROOMS+"corpse_market",
		"east": ROOMS+"marketplace2",
		"south": ROOMS+"marketplace3",
		"west": ROOMS+"merchant_road1"
	]) );
	set_door("door", ROOMS+"corpse_market", "north",
		"kuril corpse market key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "18:00:00");
	set_close_function("close_door", "06:00:00");
}

//void open_door() {
	//call_other(ROOMS+"corpse_market", "open_door");
//}

//void close_door() {
	//call_other(ROOMS+"corpse_market", "close_door");
//}

int no_exit() {
	return 1;
}
