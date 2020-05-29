// /wizards/excelsior/mon/greater_gnome

#include <std.h>

inherit MONSTER;

void make_me_boots();

void reset() {
	::reset();
	if(!present("boots")) make_me_boots();
}

void create() {
	::create();
	set_name("gnome");
	set("id",({"gnome","a gnome","a poor gnome","a greater gnome","greater gnome"}));
	set_level(13);
	set("short","A greater gnome");
	set("long","This gnome has been bred like an animal in the gnome farms. "+
		"He looks in a bit better shape then other gnomes you've seen, and "+
		"is thus probably more powerful.");
	set("race","gnome");
	if(random(2)) {
		set_gender("male");
	} else {
		set_gender("female");
	}
	set_body_type("human");
   set_overall_ac( 20 );
	set_combat_chance(95);
	set_skill("melee",20);
	set_stats("wisdom",97);
	set_stats("intelligence",95);
	add_spell("cure critical wounds","$(ME)");
	set_spell_level("cure critical wounds",4);
	add_spell("ice dagger","$A");
	set_spell_level("ice dagger",5);
	add_spell("magic missle","$A");
	set_spell_level("magic missle",5);
	add_spell("power word, stun","$A");
	set_spell_level("power word, stun",4);
	add_spell("elemental bolt","$A");
	set_spell_level("elemental bolt",4);
	set_skill("elementalism",65);
	set_max_hp(1400);
	set_hp(1300);
	set_max_mp(3500);
	set_mp(3500);
	set_skill("prayer",70);
	call_out("reset",1);
	set_skill("conjuration",81);
	set_skill("magery",73);
}

void make_me_boots() {
	object boots;
	boots = new("/std/armour");
	boots->set_name("boots");
	boots->set("id",({"gnome boots","boots"}));;
	boots->set("short","A pair of gnome boots");
	boots->set("long","This is a pair of gnome boots with pointy toes.");
	boots->set_type("boots");
	boots->set_ac(4);
	boots->set_limbs(({"right foot","left foot"}));
	boots->set_weight(93);
	boots->set_value(30);
	boots->move(this_object());
	force_me("wear boots");
}

string query_element() { return "wind"; }
