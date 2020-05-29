#include <std.h>
#include "nevin.h"
inherit MONSTER;

void create(){
	string var, var2;
	string poss, sub;
	object ob;
	int HPBASE, LEV;

	HPBASE = 20;

	::create();
	set_name("watchman");
	set("id", ({"watchman", "kuril city watchman" }) );
	set_level(13 + random(5));
	switch(random(2)) {
		case 0: var = "female"; break;
		case 1: var = "male"; break;
	}
	this_object()->set_gender(var);
	poss = (string)this_object()->query_possessive();
	sub = (string)this_object()->query_subjective();
	switch(random(5)) {
		case 0: var = "A dark robed watchman";
			var2 = "Dedicated to the protection of the School "
				"of Necromancy, these dark robed watchman "
				"of Kuril are really agents of the School "
				"of Magic.  They do not care for the citizens "
				"or the affairs of the nobles of this city, "
				"their only concern in life, and some in "
				"death, is to please their masters.";
			break;
		case 1: var = "A pale faced watchman";
			var2 = "It is said that those who practice the "
				"dark arts, begin to loose a portion of their "
				"mortality.  Looking at this watchman gives "
				"great credence to such superstitions.  Pale "
				"skin, almost marble white, covers "+poss+
				" body like a taut piece of cloth.";
			break;
		case 2: var = "A hollow eyed watchman";
			var2 = "Having witnessed the horrors of "+poss+
				"profession to many times has left this "
				"person unable to rest at night.  Dark "
				"fears and terrors surface each night, "
				"making rest impossible.   Only the cold "
				"embrace of death can rid this person "
				"of "+poss+" demons.";
			break;
		case 3: var = "A silent watchman";
			var2 = "Quietly keeping an eye upon all travelers, "
				"this watchman is careful not to let any "
				"of those troublesome priests of that "
				"foul temple near the School of Magic.  "
				"When questioned about the temple "+sub+
				"mutters something about 'dealing with "
				"those foul creatures'.";
			break;
		case 4: var = "A white knuckled watchman";
			var2 =  "Taking a firm grip of "+poss+" weapon, "
				"a stern face greets you.  But under that "
				"facade of calm is an ocean of apprehension.  "
				"'Change will come to this city...soon' "
				+sub+" says.  There seems to be a great deal "
				"of tension in Kuril.  You can see it in "
				"the citizens and in the those who claim "
				"to rule here.  The tides of war are coming.";
			break;
	}
	this_object()->set("short", var);
	this_object()->set("long", var2);
	switch(random(11)) {
		case 0: var = "werebear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "sword-demon"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "werewolf"; break;
		case 6: var = "drow-elf"; break;
		case 7: var = "gerudan"; break;
		case 8: var = "high-elf"; break;
		case 9: var = "half-elf"; break;
		case 10: if(random(10) == 0) { var = "seraph"; break; }
			else { var = "high-man"; break; }
	}
	this_object()->set("race", var);
	if(this_object()->query_race() == "sword-demon") {
		set_body_type("winged-humanoid");
	}
	else if(this_object()->query_race() == "seraph") {
		set_body_type("winged-humanoid");
	}
	else { set_body_type("human"); }
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("necromancer");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();

	set_skill("necromancy", LEV * 6);
	set_skill("prepare corpse", LEV * 6);
	set_skill("control undead", LEV * 5);
	set_skill("concentrate", LEV * 4);

	set_combat_chance(100);
	add_spell("decay", "$A");
	set_spell_level("decay", 4);
	add_spell("lifesteal", "$A");
	set_spell_level("lifesteal", 2);
	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(100));
	new(ARM+"pitch_black_robe")->
		move(this_object());
	force_me("wear robe");
	new(ARM+"hard_boots")->
		move(this_object());
	force_me("wear boots");
	new("/d/damned/virtual/dagger_5.weapon")->move(TO);
	force_me("wield dagger in left hand");
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Watchman!", a) == 1) {
		call_out("kill_them", 1, a);
		return;
	}
}

void kill_them(string who) {
	string str;
	str = "You shall soon serve us for eternity...";
	force_me("cackle");
	force_me("kill "+who);
	return;
}

int chk_my_mob() {
	return 1;
}
