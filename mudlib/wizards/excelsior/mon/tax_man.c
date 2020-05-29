// /wizards/excelsior/mon/tax_man
// Excelsior 7-2-96

inherit "/std/monster";

void make_me_paperweight() {
	object ob;
	ob = new("/std/weapon");
	ob->set_name("paperweight")
;
	ob->set("id",({"paperweight","weight"}));
	ob->set("short","paperweight");
	ob->set("long","This paperweight could be used as a weapon.");
	ob->set_weight(100);
	ob->set_value(4);
	ob->set_wc(3);
	ob->set_ac(1);
	ob->set_type("blunt");
	ob->set_quality(2);
	ob->move(this_object());
	command("wield weight in right hand");
}


void reset() {
	::reset();
	if(!present("weight"))
		make_me_paperweight();
}

void create() {
	::create();
	set_name("tax man");
	set("id",({"tax","man","tax man"}));
	set("short","He's the tax man");
	set_level(2);
	set("race","human");
	set("long","The tax man has told all these people he will see no one else "+
		"today. For many of them that means arrest for not seeing him in time.");
	set_gender("male");
	set_body_type("human");
	set_overall_ac( 2 );
	reset();
}
