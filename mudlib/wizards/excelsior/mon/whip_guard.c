// /wizards/excelsior/mon/whip_guard

#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("guard");
	set("id",({"guard","torturer","interrogator","wife beater","beater"}));
	set_level(13);
	set_gender("male");
	set("short","An 'interrogator'");
	set("long","This guard is busy forcing valuable information "+
		"out of a prisoner with his whip.");
	set("race","gromek");
	set_body_type("gromek");
	set_overall_ac(3);
	set_emotes(30,({"The guard cracks his whip at the prisoner",
		"The guard smacks the prisoner one across the face.","The guard "+
		"spits on the prisoner","The guard threatens the prisoner with "+
		"death."}),0);
	set_skill("melee",75);
	set_skill("blade",60);
	set_skill("flail",80);
	set_skill("two handed polearm",61);
	set_skill("parry",75);
}

void reset() {
	::reset();
	if(!present("whip",this_object()))
		new("/wizards/excelsior/weapons/whip")->move(this_object());
	force_me("wield whip in right hand");
}
