#include <std.h>
#include "nevin.h"
inherit MONSTER;

void create() {
	string var;
	::create();
	set_name("zombie");
	set_id( "zombie" );
	set("race", "undead");
	set_body_type("human");
	set_level(random(5) + 1);
	switch(random(17)) {
		case 0: var = "A rotting zombie"; break;
		case 1: var = "A half decayed zombie"; break;
		case 2: var = "A scavenging zombie"; break;
		case 3: var = "A pale zombie"; break;
		case 4: var = "A disease infested zombie"; break;
		case 5: var = "A charred zombie"; break;
		case 6: var = "A wandering zombie"; break;
		case 7: var = "A pox ridden zombie"; break;
		case 8: var = "A puss-oozing zombie"; break;
		case 9: var = "A parched skinned zombie"; break;
		case 10: var = "A long-limbed zombie"; break;
		case 11: var = "A hairy zombie"; break;
		case 12: var = "A foul smelling zombie"; break;
		case 13: var = "A retched zombie"; break;
		case 14: var = "A crazed zombie"; break;
		case 15: var = "A flesh eating zombie"; break;
		case 16: var = "A monstrous zombie"; break;
	}
	this_object()->set("short", var);
	set_long(
		"Rotting pieces of flesh fall away from this horrid creature."
	);
	set_property("physical resistance", ([
		"default": 25,
		"iron": 25,
		"wood": 25
	]) );
	set_property("enhance criticals", ([
		"holy": 1,
		"impaling": -1
	]) );
	set_property("melee damage", ([
		"crushing": 15,
	]) );
	set_emotes(1, ({
		"A zombie walks around in circles, it appears to be very lost.",
		"A zombie shuffles about you, where it's going you have no "
			"idea.",
		"A zombie moans something unintelligible.",
		"A newly created zombie, mutters its name over and over...fear "
			"not, for it will soon forget even that.",
	}), 0);
	new(ARM+"tattered_clothes")->
		move(this_object());
	force_me("wear tattered clothes");
}

int chk_kuril_undead() {
	return 1;
}

int chk_my_mob() {
	return 1;
}
