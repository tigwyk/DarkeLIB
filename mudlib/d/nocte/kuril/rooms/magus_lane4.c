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
		if(!query_open("door")) {
			add_action("no_exit", "east");
		}
	}
	add_action("open_the_gate", "open");
	add_action("no_close", "close");
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new(MON+"wm_necromancer")->
			move(this_object());
	}
	if(!present("sentry")) {
		new(MON+"sentry")->
			move(this_object());
		new(MON+"sentry")->
			move(this_object());
	}
	if(!present("citizen")) {
		new(MON+"kuril_cit_lw")->move(TO);
	}
}

void create(){
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("night light", -4);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n   | \n   0\nMagus Lane");
	set("long",
		"Just west of the south guard post, you can see the end of "
		"Magus Lane to the south.  Each night the South Ward Gate is "
		"closed to prevent the criminal elements of Kuril from "
		"gaining access to the Noble Ward.  Seems a little "
		"contradictory to you that the City Watch is concerned about "
		"thieves and criminals when they are often no better than "
		"the rest of those currs and ruffians.  Past the ward gate to "
		"the west are the remains of a temple.  From here you can see "
		"corpses hanging from the walls of the temple.  A pillar of "
		"dark smoke rises from the collapsed dome of the temple.  "
		"The combination of smoke and the shadow of the looming school "
		"of magic to the east makes for a very gloomy street.\n   0\n   | \n0--@--0\n   | \n   0\n"
	);
	set_items( ([
		({"post", "guard post"}): "From the condition of the exterior "
			"of the guard post, it appears to be rarely used.",
		"temple": "The temple's walls shimmer with a dull redish "
			"glow.  Every once in awhile a spark of energy "
			"burns another mark into the surface of the temple "
			"walls.",
		"smoke": "From the constant smoke coming from the temple, "
			"it appears that something big is happening in there.",
		"school": "You begin to feel very uncomfortable standing here "
			"next to the School of Necromancy.",
		"street": "Darkish water flows southward as black rain begins "
			"to fall." 
	]) );
	set_exits( ([
		"north": ROOMS+"magus_lane3",
		"south": ROOMS+"magus_lane5",
		"west": ROOMS+"temple_plaza2"
	]) );
    add_exit("/d/1tlny/complete/kuril/s1/south_guard_post.c","east");
	set_door("door", ROOMS+"south_guard_post", "east",
		"kuril south guard post key");
	set_open("door", 1);
	set_locked("door", 0);
	set_door("ward gate", ROOMS+"temple_plaza2", "west",
		"kuril south ward gate key");
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	set_open_function("open_gate", "05:20:00");
	set_close_function("close_gate", "17:20:00");
	new(MISC+"ward_gate3")->
		move(this_object());
}

void open_gate() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	call_other(ROOMS+"temple_plaza2.c", "set_locked",
		"ward gate", 0);
	call_other(ROOMS+"temple_plaza2.c", "set_open",
		"ward gate", 1);
	this_object()->reset();
	say("With the changing of the watch, the gates to the "
		"city's lower wards are reopened for the day.");
}

void close_gate() {
	set_open("ward gate", 0);
	set_locked("ward gate", 1);
	call_other(ROOMS+"temple_plaza2.c", "set_locked",
		"ward gate", 1);
	call_other(ROOMS+"temple_plaza2.c", "set_open",
		"ward gate", 0);
	this_object()->reset();
	say("With the arrival of the night watch, the gates to "
		"the city's lower wards are closed.");
}

int open_the_gate(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(query_open("ward gate")) { return 0; }
		if(TO->check_sentry()) {
			if(!(TP->query_class() == "necromancer")) {
				message("info", "A gate sentry yells at "
					"you for trying to open the ward "
					"gate.", TP);
				message("info", TPQCN+" is yelled at by a gate "
					"sentry from trying to open the ward "
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
		call_other(ROOMS+"temple_plaza2", "force_open");
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
	message("info", "The gate sentry opens the gate from the other side.");
	call_other(ROOMS+"temple_plaza2", "force_open");
	call_out("close_the_gate", 5);
}

void close_the_gate() {
	set_open("ward gate", 0);
	set_locked("ward gate", 0);
	call_other(ROOMS+"temple_plaza2", "force_closed");
	message("info", "The gate sentry closes the gate.", TO);
	message("info", "The ward gate is shut from the other side by a "
		"gate sentry", ROOMS+"temple_plaza2");
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
			message("other_action", "The gate sentry spits in " +
				(string)this_player()->query_cap_name()+
				"'s face.",
				this_object(), ({ this_player() }));
			return 1;
		}
		else {
			message("my_action", "You pass some money"
				" to the gate sentry.", 
				this_player());
			message("other_action", (string)this_player()->
				query_cap_name()+ " passes some money to the "
				"gate sentry.", 
				this_object(), ({ this_player() }));
			if((int)TP->query_money("silver") < money) {
				TP->add_money("gold", -money2);
			}
			else { this_player()->add_money("silver", -money); }
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
				inv[i]->add_money("gold", 5);
				return;
			}
		}
	}
}

int check_sentry() {
	if(present("sentry")) { return 1; }
	return 0;
}
