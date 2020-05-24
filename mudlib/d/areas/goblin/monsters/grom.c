#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("grom");
	set_id( ({"goblin", "grom"}) );
	set_level(4);
	set_short("[4]Grom the Paunch of Misty Mountain");
	set_long("A large obese goblin with a belly the size of a boulder.  This goblin is about 6' tall, evil looking, with a sharp determination in his eyes.");

	set_body_type("human");
	set("race", "goblin");
	set_stats("strength", 60);
	set_stats("dexterity", 40);
	set_stats("constitution", 100);
	set_skill("melee", 50);
	set_skill("two handed blade", 80);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_overall_ac(8);
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 30);
	set_skill("block", 40);
	set_alignment(-50);
	set_spell_level("regeneration", 6);
	set_spell_level("cure light wounds", 6);
	add_spell("regeneration", "$(ME)");
	add_spell("cure light wounds", "$(ME)");
	set_combat_chance(120);
	set_property("ambidextry", 1);
	set("aggresive", 1);
	set_skill("prayer", 100);
set_languages( ({"common"}) );
	set_speech(10, "common", ({"You are weak!", "You're such a baby, go home to your Mama!", "Die wretched scum!"}),1 );
	set_money("gold", 10);
new(ITEM+"gaxe.c")->move(this_object());
force_me("wield axe in left hand and right hand");
}
