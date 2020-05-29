#include <std.h>
#include "nevin.h"
inherit MONSTER;

void init() {
	::init();
	if(query_night()) {
		if(!wizardp(this_player())) {
			this_object()->move(ROOMS+"incinerator");
		}
	}
}

void create(){
	string var;
	object ob;
	int HPBASE, LEV;

	HPBASE = 100;

	::create();
	set_name("watchman");
	set("id", ({"watchman", "kuril city watchman" }) );
	set_level(12 + random(5));
	set("short", "A city watchman");
	set("long",
		"The elite of the city guard, the watchmen of Kuril are "
		"dedicated to following the orders of their superiors."
	);
	switch(random(12)) {
		case 0: var = "were-bear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "sword-demon"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "were-wolf"; break;
		case 6: var = "salamander"; break;
		case 7: var = "storm-giant"; break;
		case 8: var = "ogre"; break;
		case 9: var = "troll"; break;
		case 10: var = "gerudan"; break;
		case 11: var = "gromek"; break;
	}
	this_object()->set("race", var);
	switch(random(5)) {
		case 0: var = "female"; break;
		case 1: var = "female"; break;
		case 2: var = "male"; break;
		case 3: var = "male"; break;
		case 4: var = "male"; break;
	}
	this_object()->set_gender(var);
	if(TO->query_race() == "sword-demon") {
		set_body_type("winged humanoid");
	}
	else { set_body_type("human"); }
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();

	set_skill("two handed flail", LEV * 7);

	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(100) );
	ob = new(WEAP+"huge_star");
	ob->move(this_object());
	force_me("wield morning star in right hand and left hand");
	new("/d/damned/virtual/chain-mail.armour")->
		move(this_object());
	force_me("wear chain mail");
	new("/d/damned/virtual/chain-coif.armour")->
		move(this_object());
	force_me("wear coif");
	new("/d/damned/virtual/chain-greaves.armour")->
		move(this_object());
	force_me("wear greaves");
	new("/d/damned/virtual/studded-leather-glove.armour")->
		move(this_object());
	force_me("wear glove on right hand");
	new("/d/damned/virtual/studded-leather-glove.armour")->
		move(this_object());
	force_me("wear glove on left hand");
	new(ARM+"hard_boots")->
		move(this_object());
	force_me("wear boots");
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Watchman!", a) == 1) {
		call_out("kill_them", 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Citizen!", a) == 1) {
		call_out("kill_them", random(5) + 5, a);
		return;
	}
	if(sscanf(str, "%sattacks Merchant!", a) == 1) {
		call_out("kill_them", random(3) + 3, a);
		return;
	}
}

void kill_them(string who) {
	string str;
	str = "Get out of town!";
	force_me("say "+str);
	force_me("kill "+who);
	return;
}

int chk_my_mob() {
	return 1;
}
