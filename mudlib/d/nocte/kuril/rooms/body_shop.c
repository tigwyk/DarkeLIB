#include <std.h>
#include "nevin.h"

inherit "std/vault";

void init() {
	::init();
	add_action("sell_corpse", "sell");
}

void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("night light", 2);
	set_property("no castle", 1);
	set("short", "    \n     \n   @   \n   | \n   0\nBody Shop");
	set("long",
		"Specializing in the purchase of dead bodies and corpses, "
		"this shop buys any bodies.  These bodies are used by the "
		"many necromancers in town for experiments and their foul "
		"magic.\n    \n     \n   @   \n   | \n   0\n"
	);
	set_items( ([
		"sign": "The sign reads: 'say Abeyaratne, help' for assistance",
		"door": (: call_other, this_object(), "look_door" :),
	]) );
	set_exits( ([
		"south": ROOMS+"merchant_road1"
	]) );
	set_door("door", ROOMS+"merchant_road1", "south", 0);
	set_open("door", 1);
	set_locked("door", 0);
}

int sell_corpse(string str) {
	object *inv;
	string *id;
	int i, j;
	if(!str) { return 0; }
	if(!(str == "corpse")) { return 0; }
	inv = all_inventory(TP);
	i = sizeof(inv);
	while(i--) {
		id = inv[i]->query_id();
		j = sizeof(id);
		while(j--) {
			if(id[j] == "corpse") {
				inv[i]->move(ROOMS+"incinerator");
			message("info", "You give the corpse you are carrying "
				"to Abeyaratne in exchange for some silver.",
				TP);
			TP->add_money("silver", 10);
			return 1;
			}
		}
	}
	message("info", "But you do not have a corpse on you!", TP);
	return 1;
}

void reset() {
	::reset();
	seteuid(getuid());
	if(!present("abeyaratne")) {
		new(MON+"abeyaratne")->move(this_object());
	}
}

void look_door() {
	if(query_open("door")) {
		write("The door to the Body Shop is wide open.");
	}
	else {
		write("The door to the Body Shop is closed.");
	}
}
