// /wizards/excelsior/mon/ogre_guard

#include <std.h>

inherit MONSTER;

void reset() {
	::reset();
	if(!present("spear",this_object()))
		new("/wizards/excelsior/weapons/spear")->move(this_object());
	if(!present("helmet",this_object()))
		new("/wizards/excelsior/armor/guard_helmet")->move(this_object());
	if(!present("chainmail",this_object()))
		new("/wizards/excelsior/armor/guard_chainmail")->move(this_object());
	force_me("wield spear in right hand and left hand");
	force_me("wear helmet");
	force_me("wear chainmail");
}

void create() {
	::create();
	set_name("guard");
	set("id",({"guard","a guard"}) );
	set_level( 14 );
	set_gender("male");
	set("short","An immense ogre guard");
	set("long","This guard is walking around ON the gnomes "+
			"stabbing various ones with his spear. He is very ugly and "+
			"incredibly mean looking.");
	set("race","ogre");
	set_body_type("human");
	set_overall_ac(5);
	set_skill("melee",66);
	set_skill("blade",65);
	set_skill("two handed polearm",69);
	set_skill("parry",75);
	set("aggressive",1);
	set_class("fighter");
	call_out("reset",1);
}
