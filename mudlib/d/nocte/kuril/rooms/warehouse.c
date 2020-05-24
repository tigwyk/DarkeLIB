// Coder: %^GREEN%^nEv!N%^RESET%^
// Darkemud

#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("open_stuff", "open");
}

void create() {
	::create();
	set_property("indoors", 1);
	set_property("light", 1);
	set_property("night light", 0);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@   \n    \n   \nWarehouse");
	set("long",
		"Cold and damp, this warehouse stores a large number of goods."
		"  Many have been sitting here for a long time from the smell."
		"  Boxes, crates, and barrels fill the warehouse from floor "
		"to ceiling.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		"goods": "From the markings on the sides of the various "
			"containers, they are from around the world.",
		({ "boxes", "box" }): (: call_other, TO, "look_box" :),
		({ "crates", "crate" }): (: call_other, TO, "look_crate" :),
		({ "barrels", "barrel" }): (: call_other, TO, "look_barrel" :)
	]) );
	set_door("door", ROOMS+"merchant_road3", "west", 0);
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "06:00:00");
	set_close_function("close_door", "18:00:00");
	set_exits( ([
		"west": ROOMS+"merchant_road3"
	]) );
}

void look_box() {
	message("info", "The boxes are closed.", TP);
}

void look_crate() {
	message("info", "The crates are closed.", TP);
}

void look_barrel() {
	 message("info", "The barrels are sealed shut.", TP);
}

int open_stuff(string str) {
	if(!str) {
		notify_fail("What do you wish to open?");
		return 0;
	}
	switch(str) {
		case "box": (: call_other, TO, "open_obj" :); break;
		case "boxes": (: call_other, TO, "open_obj" :); break;
		case "crate": (: call_other, TO, "open_obj" :); break;
		case "crates": (: call_other, TO, "open_obj" :); break;
		case "barrel": (: call_other, TO, "open_obj" :); break;
		case "barrels": (: call_other, TO, "open_obj" :); break;
	}
}

void open_obj() {
	message("info", "You can't open those!", TP);
	return;
}

void open_door() {
	set_locked("door", 0);
	set_open("door", 1);
	call_other(ROOMS+"merchant_road3", "set_locked", "door", 0);
	call_other(ROOMS+"merchant_road3", "set_open", "door", 1);
	TO->reset();
}

void close_door() {
	object ob, *inv;
	int i;
	inv = all_inventory(TO);
	i = sizeof(inv);
	while(i--) {
		if(living(inv[i])) {
			message("info", "A dockhand pushes you out of the "
				"warehouse and locks up the door.", inv[i]);
			inv[i]->move(find_object_or_load(ROOMS+
				"merchant_road3"));
		}
	}
	set_open("door", 0);
	set_locked("door", 1);
	call_other(ROOMS+"merchant_road3", "set_locked", "door", 1);
	call_other(ROOMS+"merchant_road3", "set_open", "door", 0);
}
