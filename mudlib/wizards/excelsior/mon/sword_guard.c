// /wizards/excelsior/mon/sword_guard

inherit "std/monster";

void create() {
	::create();
	set_name("guard");
	set("id",({"guard","sword guard","a guard"}) );
	set_level(9);
	set_gender("male");
	set("short","A guard at his post");
	set("long","It appears that though the New Faerie Dust Government "+
		"has taken the position that all non-humans are inferior, they are "+
		"not below standing on guard duty for various places.");
	set("race","seraph");
	set_body_type("human");
	set_overall_ac(5);
	set_skill("melee",55);
	set_skill("blade",60);
	set_skill("two handed polearm",61);
	set_languages( ({"common"}) );
	set_skill("parry",60);
	call_out("reset",1);
}

void reset() {
	::reset();
	if(!present("sword",this_object()))
		new("/wizards/excelsior/weapons/short_sword")->move(this_object());
	if(!present("chainmail",this_object()))
		new("/wizards/excelsior/armor/guard_chainmail")->move(this_object());
	command("wear chainmail");
	command("wield sword in right hand");
}
