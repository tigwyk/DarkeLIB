#include <std.h>
#include "nevin.h"
inherit "/std/vault";

void init() {
	::init();
	add_action("bribe_sentry", "bribe");
	if(this_player()->chk_my_mob()) {
		if(!query_open("ward gate")) {
			add_action("no_exit", "east");
		}
	}
	if(TP->chk_temple_mob()) { add_action("no_exit", "east"); }
	add_action("open_the_gate", "open");
	add_action("no_close", "close");
}

void reset() {
	object ob;
	::reset();
	if(!query_night()) {
		if(!present("guard")) {
			new(MON+"wm_chaotic")->move(TO);
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
	if(query_night()) {
		if(!present("wight")) {
			new(MON+"ku_wight")->move(TO);
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
	set("short", "   \n    \n0--@--0\n    \n   \nTemple Plaza");
	set("long",
		"Standing before this evil temple, you feel small and "
		"insignificant next to the tide of evil that flows "
		"about you like an impenetreble sea of darkness.  Never "
		"before have you felt so unsure of yourself.  A small glow "
		"of inner confidence allows you to keep your head up as "
		"you quickly continue onward.  The temple's walls are "
		"scared and marked with burns and carved runes.  The runes "
		"glow with a redish light.  The entire effect is to make the "
		"temple look like it has been cut apart and left to bleed to "
		"death...\n   \n    \n0--@--0\n    \n   \n"
	);
	set_items( ([
		({"runes", "sigils"}): (: this_object(), "look_sigils" :),
		"temple": "From some remaining architectural clues, you can "
			"tell that this was once an elven structure.",
		"walls": "They are covered with red glowing runes."
	]) );
	set_exits( ([
		"east": "magus_lane4",
		"west": "temple_plaza1"
	]) );
	set_door("ward gate", ROOMS+"magus_lane4", "east",
		"kuril south ward gate key");
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
	set_open_function("open_gate", "05:20:00");
	set_close_function("close_gate", "17:20:00");
	new(MISC+"ward_gate4")->
		move(this_object());
}

int open_the_gate(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(query_open("ward gate")) { return 0; }
		if(call_other(ROOMS+"magus_lane4", "check_sentry")) {
			if(!(TP->query_class() == "necromancer")) {
				message("info", "A gate sentry yells at "
					"you for trying to open the "
					"ward gate", TP);
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
			ROOMS+"magus_lane4");
		call_other(ROOMS+"magus_lane4", "force_open");
		if(call_other(ROOMS+"magus_lane4", "check_sentry")) {
			call_out("delay_close", 5);
		}
		return 1;
	}
}

void delay_close() {
	call_other(ROOMS+"magus_lane4", "close_the_gate");
}

int no_close(string str) {
	if(!str) { return 0; }
	if( (str == "ward gate") || (str == "gate") ) {
		if(!query_open("ward gate")) { return 0; }
		if(!call_other(ROOMS+"magus_lane4", "check_sentry")) {
			return 0;
		}
		message("info", "The sentry tells you, 'Hey!  I can take "
			"care of that!  Back off!'", TP);
	}
	return 1;
}

void force_open() {
	set_open("ward gate", 1);
	set_locked("ward gate", 0);
}

void force_closed() {
	set_open("ward gate", 0);
	set_locked("ward gate", 0);
}
 
void open_gate() {
	call_other(ROOMS+"magus_lane4", "open_gate");
}

void close_gate() {
	call_other(ROOMS+"magus_lane4", "close_gate");
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

int bribe_sentry(string str) {
	int money, money2;
	money = 100;
	money2 = 5;

	if(!str) {
		notify_fail("Who do you with to bribe?\n");
		return 0;
	}
	if(str == "sentry") {
		if(!call_other(ROOMS+"magus_lane4",
			"check_sentry")) {
			notify_fail("That person is not here!\n");
			return 0;
		}
		if( ((int)this_player()->query_money("silver") < money) &&
			((int)TP->query_money("gold") < money2) ) {
			message("my_action", "The sentry spits in your face"
				"for being a cheap lout.",
				this_player());
			message("other_action", "The gate sentry spits in "+
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
				query_cap_name()+ " passes some money a "
				"gate sentry.",
				this_object(), ({ this_player() }));
			if((int)TP->query_money("silver") < money) {
				TP->add_money("gold", -money2);
			}
			else { this_player()->add_money("silver", -money); }
			call_other(ROOMS+"magus_lane4", "bribe_gate");
			call_other(ROOMS+"magus_lane4", "pay_guard");
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
