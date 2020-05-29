// /wizards/excelsior/mon/guard
// the theater guard

inherit "std/monster";

void create() {
	::create();
	set_name("guard");
	set("id",({"theatre guard","guard","a guard"}));
	set_level( 20 );
	set("short","A theatre guard");
	set("long","This is an storm-giant that has been hired to guard "+
		"the theatre. Looking at his impressive build you realize "+
		"he is a black belt in karate. If you think you're really "+
		"good you might be able to take him, but no one is betting "+
		"for you.");
	set("race","storm-giant");
	set_gender("male");
	set_body_type("human");
  set_overall_ac(100);
   set_melee_damage( (["strikes":35]) );
   set_max_hp ( 3500 );
   set_hp( 3500 );
	set_skill("melee",120);
	set_skill("martial arts",95);
	set_skill("attack",170);
	set_skill("attack",150);
	set_skill("dodge",100);
}
