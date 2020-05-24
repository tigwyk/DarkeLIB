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
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
		//if(!present("merchant")) { 
			//new(MON+"merchant2")->move(TO);
		//}
		//if(!present("cart")) {
			//new(MISC+"cart2")->move(TO);
		//}
		if(!present("watchman")) {
			new(MON+"mp_fighter")->move(TO);
			new(MON+"mp_fighter")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nMarketplace");
	set("long",
		"Kurilian citizens and merchants trade, barter, and sell "
		"items from all around the world.  "
		"Never have you seen such a huge marketplace before!  The "
		"number of people is just astounding.  From the many different "
		"faces you can see that most are not from Kuril.  In fact, "
		"most come during the day but make sure they are gone by "
		"nightfall....  To the north is a small candle shop. \n   0\n   | \n0--@--0\n   | \n   0\n "
	);
	set("night long",
		"A heavy fog rolls around you, in an all to eerie way, the "
		"billowing clouds of fog engulf you into darkness.  You can "
		"hear voices far to the east.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"shop": "Well, why don't you go and take a look for " +
			"yourself?",
		"citizens": "On closer inspection you notice that not all " +
			"of the residents of this city are still alive...",
		"merchants": "One waves you over to check out his " +
			"combination hooka and...a scream of terror " +
			"drowns out the rest of the merchant's words.",
	]) );
	set_exits( ([
		"north": ROOMS+"candle_shop",
		"east": ROOMS+"fountain_square4",
		"south": ROOMS+"marketplace4",
		"west": ROOMS+"marketplace1"
	]) );
	set_door("door", ROOMS+"candle_shop.c", "north",
		"kuril candle shop key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
}

//void open_door() {
	//call_other(ROOMS+"candle_shop.c", "open_door");
//}

//void close_door() {
	//call_other(ROOMS+"candle_shop.c", "close_door");
//}

int no_exit() {
	return 1;
}
