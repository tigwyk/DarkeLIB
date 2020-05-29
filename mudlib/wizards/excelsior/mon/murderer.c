// /wizards/excelsior/mon/murderer

#include <std.h>

inherit MONSTER;

void make_me_chain();
void make_me_clothes();

void reset() {
	::reset();
	seteuid(getuid());
	if(!present("clothes",this_object()))
		make_me_clothes();
	if(!present("chain",this_object()))
		make_me_chain();
}

void create() {
	::create();
	set_name("murderer");
	set("id",({"murderer","devil worshiper"}));
	set_level(15);
	set("short","An insane murderer");
	set("long","This is an insane murderer who is also a devil worshiper.");
	set("race","wraith");
	set_body_type("human");
	set_gender("male");
   set_overall_ac(25);
	set_skill("flail",83);
	set_stats("strength",106);
	call_out("reset",1);
}

void make_me_clothes() {
	object sp;
	sp = new("/std/armour");
	sp->set_name("clothes");
	sp->set("id",({"clothes","jail uniform","jail clothes"}));
	sp->set("short","Jailhouse clothes");
	sp->set("long","This is a complete convict uniform. It even has those "+
		"horizontal black and white stripes.");
	sp->set_type("outfit");
	sp->set_ac(1);
	sp->set_limbs(({"torso","right leg","left leg","right arm","left arm"}));
	sp->set_weight(50);
	sp->set_value(3);
	sp->move(this_object());
	force_me("wear clothes");
}

void make_me_chain() {
	object sp;
	sp = new("/std/weapon");
	sp->set_name("chain");
	sp->set("id",({"chain","large chain"}));
	sp->set("short","large chain");
	sp->set("long","This is a heavy metal chain that looks like it was ripped "+
		"out of something.");
	sp->set_weight(400);
	sp->set_value(35);
	sp->set_ac(0);
	sp->set_wc(10,"crushing");
	sp->set_type("flail");
	sp->set_quality(3);
	sp->set_hit_bonus(-20);
	sp->set_parry_bonus(-25);
	sp->move(this_object());
	force_me("wield chain in left hand");
}
