#include <std.h>
#include "nevin.h"
inherit MONSTER;

void create(){
	object ob;
	string var;
	::create();
	set_name("gate sentry");
	set_id( ({"sentry", "gate sentry" }) );
	set_level(15);
	set("short", "[15]A gate sentry");
	set("long",
		"With yellow-shot eyes, gate guard leers at you as you pass.  "
		"Well known to accept 'gifts' from travellers, they can "
		"sometimes be persuaded to let you pass through the ward gates "
		"after they are closed."
	);
	switch(random(8)) {
		case 0: var = "werebear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "gerudan"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "werewolf"; break;
		case 6: var = "troll"; break;
		case 7: var = "ogre"; break;
	}
	this_object()->set("race", var);
	set_gender("male");
	set_body_type("human");
	set_stats("strength", 100);
	set_class("fighter");
	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200));
	new("/d/damned/virtual/chain-mail.armour")->
		move(this_object());
	force_me("wear chain mail");
	new("/d/damned/virtual/chain-coif.armour")->
		move(this_object());
	force_me("wear coif");
	new("/d/damned/virtual/chain-greaves.armour")->
		move(this_object());
	force_me("wear greaves");
	new(ARM+"hard_boots")->
		move(this_object());
	force_me("wear boots");
	ob = new(WEAP+"serrated_sword.c");
	if(random(10) == 0) { ob->set_wc(3, "disruption"); }
	ob->move(this_object());
	force_me("wield sword in right hand");
new("/std/obj/lantern")->move(TO);
	if(random(10) == 0) { 
		new(ARM+"shield")->move(TO);
		force_me("wear shield on left hand");
	}
}

void catch_tell(string str) {
	string a ;
	if(sscanf(str, "%sattacks Watchman!", a) == 1) {
		call_out("kill_them", 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Gate sentry!", a) == 1) {
		call_out("kill_them", 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Citizen!", a) == 1) {
		call_out("kill_them", random(10) + 10, a);
		return;
	}
}

void kill_them(string who) {
	string str;
	str = "Prepare to die!";
	force_me("say "+str);
	force_me("spit at "+CAP(who));
	force_me("kill "+who);
	return;
}
