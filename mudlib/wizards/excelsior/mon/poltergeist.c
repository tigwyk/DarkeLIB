// /wizards/excelsior/mon/poltergeist
// Excelsior 6-28-96

inherit "/std/monster";

int query_undead() {return 1;}

void create() {
	::create();
	set_name("poltergeist");
	set("id",({"poltergeist","ghost","undead"}));
	set("undead",1);
	set("short","A fun loving poltergeist");
	set("long","This poltergeist currently has manifested itself as the generic "+
		"ghost, but could return to its poltergeisting hijinks at any time.");
	set_level(14);
	set("race","undead");
	set_gender("neuter");
	set_body_type("sphere");
	set_overall_ac(16);
	set_money("silver",734);
	set_melee_damage((["vacuum":15,"impact":18,"plasma":10]));
	set_combat_chance(50);
	add_spell("cure serious wounds","$(ME)");
	add_spell("blur","$(ME)");
	add_spell("invisibility","$(ME)");
	add_spell("fire shield","$(ME)");
	set_spell_level("cure serious wounds",4);
	set_spell_level("blur",4);
	set_spell_level("invisibility",3);
	set_spell_level("fire shield",6);
	set_skill("illusionism",75);
	set_skill("prayer",81);
	set_skill("magery",77);
	set_skill("attack",85);
	set_skill("melee",92);
	set_skill("dodge",95);
	set_skill("parry",30);
	set_emotes(30,({"Strange noises surround you.","Objects hurl at you!","You hear "+
		"laughter but see no one laughing.","You move something but when you "+
		"look again it is back where it started.","One second a table is there, "+
		"and then it is gone!","The room goes dark suddenly, the lights back up."}),
		1);
}
