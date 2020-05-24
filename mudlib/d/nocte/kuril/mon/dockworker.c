#include <std.h>
#include "nevin.h"
inherit MONSTER;

void init() {
	::init();
	if(query_night()) { 
		if(!wizardp(this_player())) {
			this_object()->move_object(ROOMS+"incinerator");
		}
	}
}

create() {
	string var, var2;
    	::create();
   	set_name("dockworker");
    	set_id( ({ "dockworker" }) );
	switch(random(4)) {
		case 0: var = "[5]A filthy dockworker";
			var2 = "Filthy from carrying heavy crates and barrels "
				"all day, the dockworker swaggers by with "
				"another heavy load.";
			break;
		case 1: var = "[5]A dingy dockworker";
			var2 = "Poorly paid and over worked, this dirty "
				"worker, toils daily to survive in this harsh "
				"city.";
				break;
		case 2: var = "[5]A lazy dockworker";
			var2 = "Not caring what his employers think, this "
				"lazy slug has decided that he is sick of "
				"working for such little pay.";
				break;
		case 3: var = "[5]An overworked dockworker";
			var2 = "Kneeling on the ground from the pain of "
				"working each and every single day, carrying "
				"extremely heavy loads, this decrepid old "
				"man can hardly keep up with the stronger, "
				"younger workers.  But the fire in his eyes "
				"refuse to give up.  With grim determination "
				"he stands back up and joins his fellows to "
				"continue their daily labors.";
				break;
	}
	this_object()->set("short", var);
	this_object()->set("long", var2);
   	set("aggressive", 0);
  	set_level(5);
   	set_gender("male");
	switch(random(9)) {
		case 0: var = "werebear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "sword-demon"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "werewolf"; break;
		case 6: var = "troll"; break;
		case 7: var = "ogre"; break;
		case 8: var = "gerudan"; break;
	}
	this_object()->set("race", var);
   	add_money("silver", ((int)this_object()->query_level()) * random(20));
	if((string)this_object()->query_race() == "sword-demon") {
		set_body_type("winged-humanoid");
	}
	else {set_body_type("human"); }
	set_wimpy(30);
        new(ARM+"soiled_pants")->
	  move(this_object());
	  force_me("wear pants");
	new(ARM+"dirty_shirt")->
	  move(this_object());
	  force_me("wear shirt");
	new(ARM+"cheap_boots")->
	  move(this_object());
	  force_me("wear boots");
	new("/d/damned/virtual/dagger_2.weapon")->
	  move(this_object());
	  force_me("wield dagger in right hand");
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Dockworker!", a) == 1) {
		call_out("dock_terror", random(5) + 15, a);
		return;
	}
}

void dock_terror(string who) {
	int i;
	string str, *exits;
	force_me("scream");
	exits = ENV(TO)->query_exits();
	i = sizeof(exits);
	force_me(exits[random(i)]);
}
	
int chk_dock_mob() {
	return 1;
}

int chk_my_mob() {
	return 1;
}
