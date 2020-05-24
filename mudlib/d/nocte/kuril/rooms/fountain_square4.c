#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("bribe_sentry", "bribe");
	add_action("read_sign", "read");
	if(this_player()->chk_mp_mob()) {
		add_action("no_exit", "east");
	}
	if(this_player()->chk_my_mob()) {
		if(!query_open("ward gate")) {
			add_action("no_exit", "east");
		}
	}
	add_action("open_the_gate", "open");
	add_action("no_close", "close");
}

void reset() {
	::reset();
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
			new(MON+"ku_wight")->move(TO);
			new(MON+"ku_wight")->move(TO);
		}
		if(!present("ghost")) { new(MON+"ghost")->move(TO); }
	}
	if(!present("zombie")) {
		new(MON+"ku_zombie")->move(TO);
	}
	if(!query_night()) {
		if(!present("citizen")) {
			new(MON+"kuril_cit_lw")->move(TO);
			new(MON+"kuril_cit_lw")->move(TO);
		}
	}
}

void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 2);
	set_property("night light", -3);
	set_property("no castle", 1);
	set("short", "   0\n   | \n0--@--0\n    \n   \nFountain Square");
	set("long",
		"An ocean breeze swirls dust into your eyes as you pass "
		"underneath a building.  To the north is a small shop "
		"protected from the rain and wind.  A small sign "
		"sways to and fro from the force of the breeze.  It's "
		"rusted chains sqeak softly.  On the ground are runes.  "
		"They connect toward a fountain to the east.  To the east "
		"a cheap gate has been put up to keep out the residents of "
		"the Lower Ward.\n    \n     \n0--@--0\n    \n   \n"
	);
	set_items( ([
		"shop": "From here you can see many fine books waiting to " +
			"be sold.",
		"building": "You are standing beneath it.",
		"sign": "Try 'read'ing it.",
		"chains": "Long rusted from the ocean breeze, they squeak "
			"softly.",
		"runes": "They trail off to the east.",
		"door": (: call_other, TO, "look_door" :)
	]) );
	set_exits( ([
		//"north": ROOMS+"book_binder",
		"east": ROOMS+"fountain_square",
		"west": ROOMS+"marketplace2"
	]) );
	set_door("door", ROOMS+"book_binder", "north",
		"kuril book binder key");
	set_open("door", 1);
	set_locked("door", 0);
	set_door("ward gate", ROOMS+"fountain_square", "east", 0);
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	set_open_function("open_door", "07:00:00");
	set_close_function("close_door", "17:00:00");
	set_open_function("open_gate", "05:20:00");
	set_close_function("close_gate", "17:20:00");
	new(MISC+"ward_gate2")->
		move(this_object());
}

int open_the_gate(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(query_open("ward gate")) { return 0; }
		if(call_other(ROOMS+"fountain_square", "check_sentry")) {
			if(!(TP->query_class() == "necromancer")) {
				message("info", "A gate sentry yells at "
					"you for trying to open the "
					"ward gate.", TP);
				message("info", "A gate sentry yells at "+
					TPQCN+" for trying to open the ward "
					"gate.", ENV(TP), ({TP}) );
				return 1;
			}
		}
		set_open("ward gate", 1);
		set_locked("ward gate", 0);
		message("info", "The gate swings open for you.", TP);
		message("info", TPQCN+" opens the ward gate.", ENV(TP),
			({TP}) );
		message("info", "The gate swings open from the other side.",
			ROOMS+"fountain_square");
		call_other(ROOMS+"fountain_square", "force_open");
		if(call_other(ROOMS+"fountain_square", "check_sentry")) {
			call_out("delay_close", 5);
		}
		return 1;
	}
}

void delay_close() {
	call_other(ROOMS+"fountain_square", "close_the_gate");
}

int no_close(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(!query_open("ward gate")) { return 0; }
		if(!call_other(ROOMS+"fountain_square", "check_sentry")) {
			return 0;
		}
		message("info", "The sentry tells you, 'Hey!  I can take care "
			"of that!  Back off!'", TP);
	}
	return 1;
}

void open_door() {
	call_other(ROOMS+"book_binder", "open_door");
}

void close_door() {
	call_other(ROOMS+"book_binder", "close_door");
}

void open_gate() {
	call_other(ROOMS+"fountain_square", "open_gate");
}

void close_gate() {
	call_other(ROOMS+"fountain_square", "close_gate");
}

void force_open() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
}

void force_closed() {
	set_open("ward gate", 0);
	set_locked("ward gate", 0);
}

void look_door() {
	if(query_open("door")) {
		write("The door to the book shop is open.");
	}
	else {
		write("The door to the book shop is closed.");
	}
}

int read_sign(string str) {
	if(!str) {
		notify_fail("What do you wish to read?");
		return 0;
	}
	if(str == "sign") {
		write("%^ORANGE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
		write("%^ORANGE%^=	 		      =");
		write("%^ORANGE%^-     %^YELLOW%^Book Binder's Shop      %^ORANGE%^-");
		write("%^ORANGE%^=			      =");
		write("%^ORANGE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	}
	return 1;
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
		if(!call_other(ROOMS+"fountain_square",
			"check_sentry")) {
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
			message("my_action", "You pass some money "
				"to the gate sentry.",
				TP);
			message("other_action", (string)this_player()->
				query_cap_name()+ " passes some money to a "
				"gate sentry.",
				ENV(TP), ({TP}));
			if((int)TP->query_money("silver") < money) {
				TP->add_money("gold", -money2);
			}
			else { TP->add_money("silver", -money); }
			call_other(ROOMS+"fountain_square", "bribe_gate");
			call_other(ROOMS+"fountain_square", "pay_guard");
			write_file("/d/nocte/kuril/logs/bribe.log", TPQCN+
				" bribed a gate sentry at "+ctime(time())+
				".\n");
			return 1;
		}
	}
}
				
int no_exit() {
	return 1;
}
