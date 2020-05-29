// /wizards/excelsior/mon/citizen
// a citizen


#include <std.h>

inherit MONSTER;

void make_lunch_box();

void reset() {
	::reset();
	if (!present("lunch box")) make_lunch_box();
}

void create() {
	::create();
	set_name("citizen");
	set("id",({"citizen","happy citizen","comrade"}) );
	set_level( 6 );
	set("short","A mindless citizen");
	set("long","This is a happy but ignorant and mindless citizen just minding "+
		"his own business. Leave him alone.");
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac( 4 );
	set_max_hp( 720 );
	set_skill("attack",55);
	set_skill("blunt",55);
	set_skill("dexterity",40);
	call_out("reset",1);
	set_moving( 1 );
	set_speed(60);
       set_money( "silver",random(300)+1);
}

void make_lunch_box() {
	object box;
	box = new("/std/weapon");
	box->set_name("club");
	box->set("id",({"club","small club"}) );
	box->set("short","small club");
	box->set("long","This is a small club carried by many NFD citizens "+
		"as protection against assailants.");
	box->set_weight( 200 );
	box->set_value( 255 );
	box->set_ac( 3 );
	box->set_wc(7,"crushing");
	box->set_type("blunt");
	box->set_quality(2);
	box->move( this_object() );
	force_me("wield club in right hand");
}
