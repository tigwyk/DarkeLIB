#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id( ({"goblin", "shaman"}) );
	set_level(3);
	set_short("[3]powerful goblin shaman");
	set_long("This is the shaman of the goblins, a spiritual leader, as well as a powerful sorcerer.  His power comes from the many mushrooms that he has.  You might want to be careful around this character.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_overall_ac(3);
	set_gender("male");
	set_casting_chance(20);
	set_combat_chance(90);
	set_spell_level("cure light wounds", 6);
	set_spell_level("ice dagger", 6);
	set_spell_level("instill poison", 6);
	set_spell_level("magic missile", 6);
	set_spell_level("cause light wounds", 6);
	add_spell("cure light wounds", "$(ME)");
	add_spell("ice dagger", "$A");
	add_spell("magic missile", "$A");
	add_spell("cause light wounds", "$A");
	add_spell("instill poison", "$A");
	set_skill("dodge", 5);
	set_skill("prayer", 70);
	set_skill("conjuration", 70);
	set_skill("body alteration", 70);
	set_skill("attack", 13);
	set_skill("magic attack", 30);
	set_skill("block", 12);
	set_alignment(-50);
new(ITEM+"staff.c")->move(this_object());
force_me("wield staff in left hand");
set_languages( ({"common"}) );
	set_stats("intelligence", 60);
	set_speech(5, "common", ({"Which mushroom to use? Which one?", "So many things to do, so little time.", "A green one, a blue one, a red one...what else?"}),1 );
	set_money("gold", 20);

}
