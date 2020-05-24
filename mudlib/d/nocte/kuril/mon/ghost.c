// Coder: %^GREEN%^nEv!N%^RESET%^
// Darkemud
// Wandering Ghost
// 10/06/96

#include <std.h>
#include "nevin.h"
inherit MONSTER;

void init() {
	::init();
	if(!query_night()) {
		if(!wizardp(this_player())) {
                            this_object()->remove();
		}
	}
}

void create() {
	string var;
	::create();
	set_name("ghost");
	set_id( ({"ghost", "spirit" }) );
	set("race", "undead");
	set_body_type("human");
	set_level(15);
	switch(random(4)) {
		case 0: var = "[15]A wandering spirit"; break;
		case 1: var = "[15]A ghastly ghost"; break;
		case 2:	var = "[15]A evil looking ghost"; break;
		case 3: var = "[1]5A screaming ghost"; break;
	}
	this_object()->set("short", var);
	set_long(
		"Reaching toward you with blood covered nails, this "
		"wails in misery at its plight..."
	);
	set_property("physical resistance", ([ "default": 25 ]) );
	set_overall_ac(20);
	set_max_hp(1500);
	set_hp(1500);
	set_skill("swimming", 200);
// incoporeal bodies-->hard to kill
	set_property("enhance criticals", ([
		"holy": 3,
		"impaling": -5,
		"cutting": -5,
		"crushing": -5,
		"impact": -5,
// they are dead so disruptions to their 'nervous' system is no effect
		"electricity": -2,
		"aether": 1,
		"cold": -5,
		"disruption": 1,
		"fire": 1,
		"paralysis": -5,
		"vacuum": -5,
		"blindness": -5,
		"contriction": -5,
		"javednite": -5,
		"plasma": -5,
		"stress": -5,
		"stun": -5
	]) );
	set_property("melee damage", ([
		"cutting": 25,
	]) );
	set_moving(1);
	set_speed(600 + random(120));
}

void heart_beat() {
	object who, *inv;
	int i;
	
	::heart_beat();
	who = TO->query_current_attacker();
	if(!who) return;
	if(!present(who)) return;
	if(random(100) < 30) {
		message("info", "%^BLUE%^%^BOLD%^The ghost lets out a "
			"cry of anguish terrible to hear!%^RESET%^", ENV(TO),
			({TO}) );
		inv = all_inventory(ENV(TO));
		i = sizeof(inv);
		while(i--) {
			if((living(inv[i])) && !(inv[i] == TO)) {
				if(! (wizardp(inv[i]) || inv[i]->query_race()
					== "undead") ) {
				if((random(100) < 5) && (random(30) >
					inv[i]->query_level())) {
				message("info", inv[i]->query_cap_name()+
					" clutches at "+inv[i]->
					query_possessive()+" heart!",
					ENV(inv[i]), ({inv[i]}) );
				message("info", "You clutch at your heart "
					"in an attempt to keep it "
					"from bursting!  OH THE PAIN!!!", 
					inv[i]);
				inv[i]->add_hp( -(inv[i]->query_max_hp()/4) );
				inv[i]->cit_flee();
				} }
			}
		}
	}
}

void die(object who) {
	message("info", "A soft voice says...'finally, rest....'", ENV(TO),
		({TO}) );
	::die(who);
	return;
}

int chk_my_mob() { return 1; }

int chk_kuril_undead() { return 1; }

int check_kuril_ghost() { return 1; }

// they float about
int query_flying() { return 1; }
