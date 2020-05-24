// /wizards/excelsior/mon/drunk_ghost.c
// Excelsior 6-28-96

inherit "/std/monster";

void make_me_mug() {
	object ob;
	ob = new("/std/Object");
	ob->set_name("mug");
	ob->set("short","A mug of beer");
	ob->set("long","An empty beer mug. A large crack in it prevents it from "+
		"holding any liquids.");
	ob->set("id",({"mug","beer mug","glass"}));
	ob->set_weight(30);
	ob->set_float_value(0.5);
	ob->move(this_object());
}

void create() {
	::create();
	set_name("ghost");
	set("id",({"ghost","drunk ghost"}));
	set_level(3);
	set("long","This ghost may have ahd a bit too much to drink.");
	set("short","[3]This ghost may have had a bit to much to drink");
	set("race","undead");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(5);
	set("undead",1);
	make_me_mug();
	set_melee_damage(60);
	reset();
}
