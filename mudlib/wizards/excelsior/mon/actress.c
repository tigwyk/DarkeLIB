// /wizards/excelsior/mon/actress
// running amuck! running amuck! running amuck!

#include <std.h>

inherit MONSTER;

void reset() {
	::reset();
	if (!present("bottle",this_object()) ) {
		new("/wizards/excelsior/weapons/bottle")->move( this_object() );
	}
	force_me("wield bottle in right hand");
}

void create() {
	::create();
	set_name("actress");
	set("id",({"actress","crazy actress"}) );
	set_level(5);
	set("short","An actress running amuck");
	set("long","This appears to be an actress at the New Faerie Dust theatre "+
		"company who has gone mad and is running amuck. She had locked herself "+
		"in her dressing room and totally trashed it.");
	set("race","human");
	set_gender("female");
	set_body_type("human");
	set_overall_ac( 4 );
	set_moving(1);
	set_speed(20);
	set_max_hp( 100);
	set_hp(100);
	set_skill("attack",75);
	set_skill("blade",80);
	set_stats("dexterity",85);
	set("aggressive", (: call_other, this_object(), "see_if_attack" :) );
	set_wimpy(50);
	set_languages( ({"common","middle-english"}) );
	set_emotes(20, ({"The actress bashes her own head into a wall.","The actress "+
		"runs around yelling loudly.","The actress does a flip in the air."}) , 0);
	set_achats(20, ({"The actress laughs in your face.","The actress does a quick "+
		"Irish jig."}) );
	call_out("reset",2);
}


void init() {
	::init();
}
int see_if_attack(object ob) {
	if( random(7) > 5 ) return 1;
}
