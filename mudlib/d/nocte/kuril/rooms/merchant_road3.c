#include <std.h>
#include "nevin.h"
inherit VAULT;

void reset() {
	::reset();
	if(!query_night()) {
		if(!present("dockworker")) {
			new(MON+"dockworker")->move(TO);
		}
		if(!present("watchman")) {
			if(random(2) == 0) {
				new(MON+"wm_fighter")->move(TO);
			}
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
	set("short", "   0\n   | \n   @--0\n   | \n   0\nMerchant Road");
	set("long",
		"Sailors and dockhands walk to and fro going about their "
		"business.  Wealthy merchant traders and poor beggars "
		"fill the streets near the Kurilian Port.  To the east is "
		"a large warehouse on the bottom floor of a large building."
		"Have you ever seen such a large collection of filth and "
		"decay in your life?\n   0\n   | \n   @--0\n   | \n   0\n"
	);
	set_items( ([
		"sailors": "One mutters under his foul breath: 'Uljan will pay "
			"for his treachery!",
		"dockhands": "They ignore you as they continue with their work.",
	]) );
	set_exits( ([
		"north": ROOMS+"merchant_road2",
		"east": ROOMS+"warehouse",
		"south": ROOMS+"merchant_road4"
	]) );
	set_door("door", ROOMS+"warehouse", "east", 0);
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "06:00:00");
	set_close_function("close_door", "18:00:00");
}

void open_door() {
	call_other(ROOMS+"warehouse", "open_door");
}

void close_door() {
	call_other(ROOMS+"warehouse", "close_door");
}
