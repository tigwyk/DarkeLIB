// /wizards/excelsior/mon/lucifer
// one bad ass mofo
// Excelsior 6-26-96

#include <std.h>

inherit MONSTER;

void reset() {
	::reset();
	if(!present("scythe"))
		new("/wizards/excelsior/weapons/devil_scythe")->move(this_object());
		command("wield scythe in right hand");
}

void create() {
	::create();
	set_name("lucifer");
	set("id",({"rhinocerous","lucifer"}));
	set_level(21);
	set("short","Lucifer the rhinocerous");
	set("concentrate",1);
	set("long","This creature is an evil incarnate. Though his body "+
		"is humanoid, he has the head of a rhinocerous and the tough "+
		"skin of one as well. You can tell that this is one bad ass mofo.");
	set("race","rhinocerous");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(30);
	set_melee_damage( (["crushing":19]) );
	set_combat_chance(50);
	add_spell("heal","$(ME)");
	add_spell("hammer of k'thach","$A");
	add_spell("faerie fire","$A");
	add_spell("slow","$A");
	add_spell("rot","$A");
	add_spell("chilling touch","$A");
	set_spell_level("heal",6);
	set_spell_level("hammer of k'thach",6);
	set_spell_level("faerie fire",5);
	set_spell_level("slow",4);
	set_spell_level("rot",6);
	set_spell_level("chilling touch",6);
	set_max_hp(2700);
	set_hp(2700);
	set_max_mp(4000);
	set_mp(4000);
	set_exp(50099);
	set_money("gold",140);
	set_stats("strength",96);
	set_stats("dexterity",82);
	set_skill("melee",50);
	set("undead",1);
	set_skill("attack",108);
	set_skill("parry",95);
	set_skill("dodge",83);
	set_skill("two handed polearm",103);
	set_skill("prayer",93);
	set_skill("worship of k'thach",100);
	set_skill("illusionism",90);
	set_skill("magery",85);
	set_skill("necromancy",95);
	set_skill("concentrate",120);
	set_wimpy(5);
	reset();
}

int query_undead() {return 1;}
