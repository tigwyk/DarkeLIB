#include "/adm/include/std.h"
#include "nevin.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV,zlevel;

	HPBASE = 100;

	::create();
	seteuid(geteuid());
	set_name("watchman");
	set("id", ({"watchman", "kuril city watchman" }) );
zlevel=(12+random(5));
if (zlevel == 16) set_short("[16]A vigilant watchman");
else 
if (zlevel == 15) set_short("[15]A strong watchman");
else
if (zlevel == 14) set_short("[14]A scarred watchman");
else
if (zlevel == 13) set_short("[13]A grim faced watchman");
else
if (zlevel == 12) set_short("[12]A burly watchman");
else set_short("[17]A vigilant watchman");
	set_level(zlevel);

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
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();
	set_skill("two handed polearm", LEV * 7);

	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
	switch(random(100)) {
		case 0..4: wc = 2; break;
		case 5..15: wc = 3; break;
		case 16..79: wc = 4; break;
		case 80..94: wc = 5; break;
		case 95..99: wc = 6; break;
	}
	switch(random(100)) {
		case 0..94: 	new(WEAP+"trident1")->move(TO);
				force_me("wield trident in right hand and left "
					"hand");
				break;
		case 95..99: 	new(WEAP+"trident2")->move(TO);
				force_me("wield trident in right hand and left "
					"hand");
	}
	new("/d/damned/virtual/chain-mail.armour")->
		move(this_object());
	force_me("wear chain mail");
	new("/d/damned/virtual/chain-coif.armour")->
		move(this_object());
	force_me("wear coif");
	new("/d/damned/virtual/chain-greaves.armour")->
		move(this_object());
	force_me("wear greaves");
	switch(random(100)) {
		case 0: new(ARM+"scaled_boots")->move(TO); break;
		default: new(ARM+"hard_boots")->move(TO);
	}
	force_me("wear boots");
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Watchman!", a) == 1) {
		call_out("kill_them", 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Citizen!", a) == 1) {
		call_out("kill_them", random(3) + 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Dockworker!", a) == 1) {
		call_out("kill_them", random(5) + 2, a);
		return;
	}
}

void kill_them(string who) {
	string str;
	str = "All trouble makers must die!  You will make a nice new "
		"corpse for the necromancers!";
	force_me("say "+str);
	force_me("grin");
	force_me("kill "+who);
	return;
}

int chk_my_mob() {
	return 1;
}
