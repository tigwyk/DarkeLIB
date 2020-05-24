#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("bribe_sentry", "bribe");
	if(this_player()->chk_my_mob()) {
		if(!query_open("ward gate")) {
			add_action("no_exit", "west");
		}
	}
	add_action("open_the_gate", "open");
	add_action("no_close", "close");
}

void reset() {
	int i;
	::reset();
	if(!present("sentry")) {
		new(MON+"sentry")->move(TO);
		new(MON+"sentry")->move(TO);
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!present("watchman")) {
		new(MON+"wm_fighter")->move(TO);
	}
	if(!present("citizen")) {
		for(i = 1; i <= 1; i++) {
			new(MON+"kuril_cit_lw")->
				move(this_object());
		}
		new(MON+"kuril_cit")->move(TO);
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("night light", -4);
	set_property("no castle", -3);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nFountain Square");
	set("long",
		"A large pool of water sits in the middle of a courtyard.  "
		"Above you is the open sky.  The road continues in each "
		"direction passing directly under a building.  What was "
		"once a beautiful fountain surrounded by intricate marble "
		"and tiles is now is a state of near ruin.  Anything of "
		"value has been striped clean--all that is left is a ring "
		"of hard stone.  Sad.  But for some reason the fountain "
		"is still functioning, although from whence the water "
		"spouts you cannot tell.  A jet of water just shoots out "
		"from the middle of the fountain to fall back into the "
		"crystal clear water.  Hmmm, if the fountain has been "
		"neglected for so long shouldn't the water be dirty?  "
		"Runes trace their way around the fountain.  Although "
		"they are worn and ancient, they speak of ancient power "
		"long forgotten.  The runes trace their way right " 
		"into the fountain.  From the fountain the runes branch "
		"off and trail to the north, south, east, and west.  "
		"A make shift gate has been erected by the city watch to "
		"keep the undesireables from the Lower Ward out during "
		"the late evening hours.  To the south is the School of "
		"Necromancy, even during the day darkness exudes from the "
		"building.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set("night long", 
		"Emerging from beneath a dark building, you find a "
		"fountain with a jet of water emerging from its clear "
		"surface.  A ward gate has been placed to the west to "
		"keep the undead of the night out of the Upper Ward.  "
		"A cry in the night stirs the peace of this place.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		"building": "Wouldn't it just be the perfect place for your "
			"very own store?"
	]) );
	set_exits( ([
		"north": ROOMS+"fountain_square1",
		"east": ROOMS+"fountain_square2",
		"south": ROOMS+"fountain_square3",
		"west": ROOMS+"fountain_square4"
	]) );
	set_listen("default", "Your hear trickling water from a sparkling "
		"fountain.");
	set_door("ward gate", ROOMS+"fountain_square4", "west", 0);
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	set_open_function("open_gate", "05:20:00");
	set_close_function("close_gate", "17:20:00");
	new(MISC+"fountain")->
		move(this_object());
	new(MISC+"ward_gate1")->
		move(this_object());
}

void open_gate() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	call_other(ROOMS+"fountain_square4", "set_locked",
		"ward gate", 0);
	call_other(ROOMS+"fountain_square4", "set_open",
		"ward gate", 1);
	this_object()->reset();
	say("With the changing of the watch, the gates to the "
		"city's lower wards are reopened for the day.");
}

void close_gate() {
	set_open("ward gate", 0);
	set_locked("ward gate", 0);
	call_other(ROOMS+"fountain_square4", "set_locked",
		"ward gate", 1);
	call_other(ROOMS+"fountain_square4", "set_open",
		"ward gate", 0);
	this_object()->reset();
	say("with the arrival of the night watch, the gates to "
		"the city's lower wards are closed.");
}

int open_the_gate(string str) {
	if(!str) { return 0;}
	if( (str == "ward gate") || (str == "gate") ) {
		if(query_open("ward gate")) { return 0; }
		if(TO->check_sentry()) {
			if(!(TP->query_class() == "necromancer")) { 
				message("info", "A gate sentry yells at "
					"you for trying to open the ward "
					"gate.", TP);
				message("info", TPQCN+" is yelled at by a gate "
					"sentry for trying to open the ward "
					"gate.", ENV(TP), ({TP}) );
				return 1;
			}
		}
		set_open("ward gate", 1);
		set_locked("ward gate", 0);
		message("info", "The gate swings open for you.", TP);
		message("info", TPQCN+" opens the ward gate.", ENV(TP), ({TP}));
		message("info", "The gate swings open from the other side.",
			ROOMS+"fountain_square4");
		call_other(ROOMS+"fountain_square4", "force_open");
		if(TO->check_sentry()) {
			call_out("close_the_gate", 5);
		}
		return 1;
	}
}

int no_close(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(!query_open("ward gate")) { return 0; }
		if(!TO->check_sentry()) {
			return 0;
		}
		message("info", "The sentry tells you, 'Hey!  I can take care "
			"of that!  Back off!'", TP);
	}
	return 1;
}

void bribe_gate() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	message("info", "The gate sentry opens the gate.", TO);
	message("info", "The gate sentry opens the gate from the other side.",
		ROOMS+"fountain_square4");
	call_other(ROOMS+"fountain_square4", "force_open");
	call_out("close_the_gate", 5);
}

void close_the_gate() {
	set_open("ward gate", 0);
	set_locked("ward gate", 0);
	call_other(ROOMS+"fountain_square4", "force_closed");
	message("info", "The gate sentry closes the gate.", TO);
	message("info", "The ward gate is shut from the other side by a "
		"gate sentry", ROOMS+"fountain_square4");
}

void force_open() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
}

int bribe_sentry(string str) {
	int money, money2;
	money = 100;
	money2 = 5;
 
	if(!str) {
		notify_fail("Who do you wish to bribe?\n");
		return 0;
	}
	if(str == "sentry") {
		if(!present("gate sentry")) {
			notify_fail("That person is not here!\n");
			return 0;
		}
		if( ((int)this_player()->query_money("silver") < money) &&
			((int)TP->query_money("gold") < money2) ) {
			message("my_action", "The sentry spits in your face "
				"for being a cheap lout.", 
				this_player());
			message("other_action", "The gate sentry spits in "+
				(string)this_player()->query_cap_name()+
				"'s face.",
				this_object(), ({ this_player() }));
			return 1;
		}
		else {
			message("my_action", "You pass some money to the "
				"gate sentry.",
				this_player());
			message("other_action", (string)this_player()->
				query_cap_name()+ " passes some money to the "
				"gate sentry.",
				this_object(), ({ this_player() }));
			if((int)TP->query_money("silver") < money) {
				TP->add_money("gold", -money2);
			}
			else { TP->add_money("silver", -money); }
			call_out("bribe_gate", 1);
			call_out("pay_guard", 2);
			write_file("/d/nocte/kuril/logs/bribe.log", TPQCN+
				" bribed a gate sentry at "+ctime(time())+
				".\n");
			return 1;
		}
	}
}

void pay_guard() {
	object *inv;
	int i;

	inv = all_inventory(TO);
	i = sizeof(inv);
	while(i--) {
		if(living(inv[i])) {
			if(inv[i]->query_name() == "gate sentry") {
				inv[i]->add_money("silver", 5);
				return;
			}
		}
	}
}

int check_sentry() {
	if(present("sentry")) { return 1; }
	return 0;
}

int no_exit() {
	return 1;
}
