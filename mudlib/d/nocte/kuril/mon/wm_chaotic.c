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

void create(){
	string var;
	object ob;
	int HPBASE, LEV,zlevel;

	HPBASE = 70;

	::create();
	set_name("temple guard");
	set("id", ({"guard", "temple guard" }) );
zlevel=(12+random(5));
if (zlevel == 16) set_short("[16]A temple guard");
else 
if (zlevel == 15) set_short("[15]A temple guard");
else
if (zlevel == 14) set_short("[14]A temple guard");
else
if (zlevel == 13) set_short("[13]A temple guard");
else
if (zlevel == 12) set_short("[12]A temple guard");
else set_short("[17]A temple guard");
	set_level(zlevel);
	set("long",
		"Standing guard about the temple of their dark lord, the "
		"temple guards are known to be both dangerous and suspicious "
		"of all who dare to approach the evil temple."
	);
	switch(random(10)) {
		case 0: var = "were-bear"; break;
		case 1: var = "vulfen"; break;
		case 2: var = "sword-demon"; break;
		case 3: var = "wraith"; break;
		case 4: var = "high-man"; break;
		case 5: var = "were-wolf"; break;
		case 6: var = "sword-demon"; break;
		case 7: var = "sword-demon"; break;
		case 8: var = "sword-demon"; break;
		case 9: var = "sword-demon"; break;
	}
	this_object()->set("race", var);
	switch(random(4)) {
		case 0: var = "female"; break;
		case 1: var = "male"; break;
		case 2: var = "male"; break;
		case 3: var = "male"; break;
	}
	this_object()->set_gender(var);
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("chaotic-lord");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_object()->query_level();
	set_skill("offhand training", LEV * 7);
	set_skill("dual attack", LEV * 7);
	set_skill("chaos magic", LEV * 5);
	set_skill("axe", LEV * 7);

	set_combat_chance(100);
	add_spell("chaos ball", "$A");
	set_spell_level("chaos ball", ((int)this_player()->query_level()) - 11);
		
	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
	if(random(10) == 0) { add_money("mithril", random(2) + 1); }
	new(WEAP+"temple_axe")->move(TO);
	new(WEAP+"temple_sword")->move(TO);
	force_me("wield battle axe in right hand");
	force_me("wield sword in left hand");
	new("/d/damned/virtual/chain-mail.armour")->
		move(this_object());
	force_me("wear chain mail");
	new("/d/damned/virtual/chain-coif.armour")->
		move(this_object());
	force_me("wear chain coif");
	new("/d/damned/virtual/studded-leather-glove.armour")->
		move(this_object());
	force_me("wear glove on right hand");
	new("/d/damned/virtual/studded-leather-glove.armour")->
		move(this_object());
	force_me("wear glove on left hand");
	new(ARM+"hard_boots")->
		move(this_object());
	force_me("wear boots");
	if(TO->query_race() == "sword-demon") {
		if(random(50) == 0) {
			new(MAGIC+"qui_ring")->move(TO);
			force_me("wear ring on right hand");
		}
	}
}

void catch_tell(string str) {
	string a;
	if(sscanf(str, "%sattacks Temple guard!", a) == 1) {
		call_out("kill_them", random(3) + 1, a);
		return;
	}
	if(sscanf(str, "%sattacks Chaos hound!", a) == 1) {
		call_out("kill_them", random(3) + 1, a);
		return;
	}
}

void kill_them(string who) {
	string str;
	str = "How dare you attempt to attack our sacred temple!";
	force_me("say "+str);
	force_me("kill "+who);
	return;
}

int chk_my_mob() {
	return 1;
}

int chk_temple_mob() {
	return 1;
}
