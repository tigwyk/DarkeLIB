// /wizards/excelsior/mon/spear_guard

// /wizards/excelsior/mon/spear_guard


inherit "std/monster";

int spear,sword,helmet,chainmail;

void create() {
	::create();
	set_name("guard");
	set("id",({"guard","a guard","spear guard"}) );
	set_level(8);
	set_gender("male");
	set("short","A guard at his post");
	set("long","It appears that though the New Faerie Dust Government "+
		"has taken the position that all non-humans are inferior, they are "+
		"not below standing on guard duty for various places.");
	set("race","storm giant");
	set_body_type("human");
	set_overall_ac(3);
	set_skill("melee",55);
	set_skill("blade",60);
	set_skill("two handed polearm",61);
	set_languages( ({"common"}) );
	set_skill("parry",55);
	call_out("reset",1);
}

void reset() {
	::reset();
	if(!present("spear",this_object()))
		new("/wizards/excelsior/weapons/spear")->move(this_object());
	if(!present("helmet",this_object()))
		new("/wizards/excelsior/armor/guard_helmet")->move(this_object());
	force_me("wear helmet");
	force_me("wield spear in right hand and left hand");
}
