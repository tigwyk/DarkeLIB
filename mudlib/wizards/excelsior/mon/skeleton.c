// /wizards/excelsior/mon/skeleton
// Excelsior 6-28-96

inherit "/std/monster";

void reset() {
	::reset();
	if(!present("battle axe")) {
		new("/wizards/excelsior/weapons/battle_axe")->move(this_object());
		command("wield axe in right hand");
	}
	if(!present("battle axe 2")) {
		new("/wizards/excelsior/weapons/battle_axe")->move(this_object());
		command("wield axe in left hand");
	}
}

void create() {
	::create();
	set_name("skeleton");
	set("id",({"skeleton","wrath","skeleton guard"}));
	set_level(12);
	set("short","skeleton guard");
	set("long","This skeleton isn't really enjoying the party, he is really just "+
		"making sure no one gets out of line.");
	set("race","wrath");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(14);
	set_max_hp(1000);
	set_hp(1000);
	set_skill("axe",76);
	set_skill("attack",75);
	set_skill("dodge",50);
	set_skill("parry",85);
	set_class("fighter");
	set_wimpy(50);
	reset();
}
