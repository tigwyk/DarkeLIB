// /wizards/excelsior/mon/booga_boo
// a scary radioactive slug. Ahhhh!

inherit "std/monster";
	
void create() {
	::create();
      this_object()->set_money("gold",random(8)+1);
;
	set_name("booga boo");
	set("id",({"boo","booga","slug","booga boo"}) );
	set_level( 10 );
	set("short","A slimy booga boo");
	set("long","This radioactive slug creature has nothing better to do "+
		"then slime around and kill things.");
	set("race","slug");
	set_gender("neuter");
	set_body_type("slug");
	set_overall_ac( 4 );
	set_melee_damage( "impact" );
	set_fingers(0);
	set_property("magic resistance",25);
	set_skill("melee",55);
		set_exp(45000);
	set_skill("conjuration",40);
	set_combat_chance(40);
	add_spell("killing cloud","$A");
	set_max_hp(500);
	set_spell_level("killing cloud",3);
	set_hp(500);
	set("aggressive",(: call_other, this_object(), "check_attack" :) );
}

int check_attack( object who ) {
	if (who->is_player()) { return 1; }
	return 0;
} 
void heart_beat() {
	object who;
	::heart_beat();
	who = this_object()->query_current_attacker();
	if(!who) return;
	if(!present(who)) return;
	if(random(100) < 5) {
		tell_object(who,"%^GREEN%^The Booga Boo spits acid all over you!");
		tell_room(environment(who),"The Booga Boo squirts acid all over "+who->query_cap_name()+".",({who})); 
		who->add_poisining(22);
	}
}

