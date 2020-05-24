#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	if(this_player()->chk_my_mob()) {
		if(!query_open("door")) {
			add_action("no_exit", "south");
		}
	}
	if(TP->chk_temple_mob()) { add_action("no_exit", "south"); }
}

void reset() {
	object ob;
	::reset();
	if(!query_night()) {
		if(!present("guard")) {
			new(MON+"wm_chaotic")->move(TO);
			new(MON+"wm_chaotic")->move(TO);
			ob = new(MON+"wm_chaotic");
			ob->set_moving(1);
			ob->set_speed(120 + random(30));
			ob->move(TO);
		}
		if(!present("hound")) {
			new(MON+"chound")->move(TO);
		}
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "\n   0\n   | \n0--@   \n   | \n   0\nThieve's Court");
	set("long",
		"To the south is the city's Parchment Shop.  An abandoned "
		"grydan wanders about looking for something to eat.  "
		"To the east is a large stone structure.  The walls of which "
		"are covered with runes and sigils.  To the north is "
		"Merchant's Road.\n   0\n   | \n0--@   \n   | \n   0\n" 
	);
	set_items( ([
		({"runes", "sigils"}): (: call_other, this_object(), 
			"look_sigils" :)
	]) );
	set_exits( ([
		"north": ROOMS+"thieves_court1",
		"south": "parchment_shop",
		"west": "thieves_court3"
	]) );
	set_door("door", ROOMS+"parchment_shop.c", "south",
		"kuril parchment shop key");
	set_open("door", 1);
	set_locked("door", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
}

int look_sigils(string str) {
	if(!str) {
		return 0;
	}
	if((str == "runes") || (str == "sigils")) {
		if((string)this_player()->query_class() == "chaotic-lord") {
			write("You immediately recognize the symbols of "
				"unholy might, summoning, and darkness.");
		}
		else {
			write("Your head begins to swim as you look at the "
				"runes and sigils");
			say((string)this_player()->query_cap_name()+
				" collapses from looking at the wall.");
			this_player()->set_paralyzed(30, "Your head is still "
				"swimming from staring at the runes and "
				"sigils!");
		}
		return 1;
	}
}

void open_door() {
	call_other(ROOMS+"parchment_shop.c", "open_door");
}

void close_door() {
	call_other(ROOMS+"parchment_shop.c", "close_door");
}

int no_exit() {
	return 1;
}
