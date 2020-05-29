// /wizards/excelsior/mon/tinker

inherit "/std/npc_shop";

void reset() {
	::reset();
	if(!present("sword"))
		new("/d/damned/virtual/two-handed-sword_3.weapon")->move(this_object());
	command("wield sword in right hand and left hand");
}

void create() {
	::create();
	set_name("bob");
	set("id",({"bob","tinker","dealer","Bob"}));
	set_level(6);
	set("short","Bob the tinker");
	set("long","Bob is not a tinker in the ordinairy since, he just goes "+
		"by that for lack of a better title. He deals in all sorts of odds "+
		"and ends. You can ask him for help if you need it.");
	set("race","wood-elf");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(6);
	set_skill("two handed blade",51);
	set_skill("attack",53);
	set_skill("dodge",30);
	set_skill("parry",24);
	set_class("tinker");
	set("storage room","/wizards/excelsior/rooms/shops/tinker_storage");
	set("mark up",5);
	set_languages(({"sylvan","elvish","hisaaa","middle-english","common",
		"rel","mountainspeak","pix","drow","hydran","zebber","lithic",
		"rachk","undead-tongue"}));
	set("no sell",1);
	reset();
}
