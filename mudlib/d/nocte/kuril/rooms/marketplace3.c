#include <std.h>
#include "nevin.h"
inherit ROOM;

void reset() {
	::reset();
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
		//if(!present("merchant")) {
			//new(MON+"merchant3")->move(TO);
		//}
		//if(!present("cart")) {
			//new(MISC+"cart3")->move(TO);
		//}
		if(!present("watchman")) {
			new(MON+"mp_fighter")->move(TO);
			new(MON+"mp_fighter")->move(TO);
		}
	}
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
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
	set("short", "   0\n   | \n0--@--0\n    \n   \nMarketplace");
	set("long",
		"Almost slipping on the slick stones, you manage to regain "
		"your balance by grabbing onto the nearest person...which "
		"just happens to be a necromancer.  You have best move along.  "
		"Vigilent watchman maintain a constant watch over the "
		"marketplace waiting for anyone to cause trouble.\n   0\n   | \n0--@--0\n    \n   \n"
	);
	set("night long",
		"The slick stones beneath your feet offer very poor footing.  "
		"To the west you can hear the ocean's waves slamming into the "
		"piers.\n   0\n   | \n0--@--0\n    \n   \n"
	);
	set_items( ([
		"stones": "The stones are covered with gore and half dried "
			"blood.  Obviously from the last evening.",
		"necromancer": "He tries to disappear into the crowd, but "
			"the sheer number of people prevents him from getting "
			"very far.",
	]) );
	set_exits( ([
		"north": ROOMS+"marketplace1",
		"east": ROOMS+"marketplace4",
		"west": ROOMS+"merchant_road2"
	]) );
}
