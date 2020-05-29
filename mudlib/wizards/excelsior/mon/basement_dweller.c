// /wizards/excelsior/mon/basement_dweller
// one tough mofo.

inherit "std/monster.c";

void reset() {
	::reset();
	force_me("wield flail in right hand and left hand");
	force_me("wear platemail");
}

void create() {
	::create();
	set_name("dweller");
	set("id",({"basement dweller","dweller","orc"}) );
	set_level( 15 );
	set("short","a well outfited basement dweller");
	set("long","This is a ferocious looking fellow. It is a large deformed "+
		"orc that has spent his life hiding in the theatre basement. It has "+
		"clad itself in some sort of modern-day platemail. This is not "+
		"something the novice adventurer should mess with.");
	set("race","half-orc");
	set_money("copper",300);
	set_money("gold",30);
	set_gender("neuter");
	set_body_type("human");
	set_overall_ac(6);
	set_max_hp( 900 );
	set_hp( 900 );
	set_skill("two handed flail",80);
	set_skill("attack",84);
	set_skill("parry",56);
	set_emotes(20, ({"The basement dweller hums the melody to 'Mary Had a "+
		"little lamb'."}) , 0);
	set_stats("strength",105);
	new("/wizards/excelsior/weapons/flail_of_death")->move( this_object() );
	new("/wizards/excelsior/armor/orc_platemail")->move( this_object() );
	call_out( "reset",1);
}
