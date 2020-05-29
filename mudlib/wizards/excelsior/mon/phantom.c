// /wizards/excelsior/mon/phantom
// first real monster of area.

#include <std.h>

inherit MONSTER;

void reset() {
	::reset();
	if(!present("cloak",this_object()))
		new("/wizards/excelsior/armor/dark_cloak")->move(this_object());
	if(!present("mask",this_object()))
		new("/wizards/excelsior/armor/mask")->move(this_object());
	force_me("wear cloak");
	force_me("wear mask");
}
void create() {
	::create();
	set_name("phantom");
	set("id",({"the phantom","phantom","man"}) );
	set_level( 15 );
	set("short","The phantom stage director");
	set("long","This is theatre companies missing stage director. He has given "+
		"up his job as an operator of the theatre to become a mysterious "+
		"masked phantom. He could be considered 'the phantom of the operator.' "+
		"The director seems to be a very skilled magic user. He is not one "+
		"you would want to mess with with." );
	set("race","human");
      this_object()->set_money("silver",500);
	set_gender("male");
	set_body_type("human");
	set_skill("melee",70);
	set_overall_ac( 5 );
	set_skill("elementalism",73);
	set_skill("chaos lore",71);
	set_skill("prayer",30);
	set_combat_chance( 80 );
	add_spell("heal","$(ME)");
	add_spell("elemental bolt","$A");
	add_spell("elemental strike","$A");
	set_spell_level("elemental bolt",5);
	set_spell_level("elemental strike",5);
	set_spell_level("heal",2);
	set_property("magic resistance",20);
	set_stats("wisdom",100);
	call_out( "reset", 1 );
}

string query_element() { return "chaos"; }
