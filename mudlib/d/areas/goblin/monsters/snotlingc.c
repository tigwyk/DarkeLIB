#include <std.h>
#include "../goblin.h"

inherit MONSTER;


void create() {
	::create();
	set_name("snotling");
	set_id( ({"snotling", "guard"}) );
	set_level(3);
	set_short("[3]rabid snotling temple guard");
	set_long("This is one of the rabid statue guards of Gork and Mork, the green skinned gods.  He is dressed in long green robes and carries a moon mace.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 20);
	set_wielding_limbs( ({"left hand", "right hand"}) );
	set_overall_ac(3);
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 13);
	set_skill("block", 12);
	set_alignment(-20);
	set_skill("blunt", 40);
	set("aggressive", 2);
	set_stats("strength", 30);
	set_stats("dexterity", 20);
set_languages( ({"common"}) );
	set_speech(5, "common", ({"Die!", "In the name of Gork and Mork die!", "You shall perish under my mace", "Eat this!"}),1 );
	set_achats(20, ({ "HA HA HA", "You better go back to your Momma!", "Is that the best you can do?", "That is pathetic!"}));
	set_money("silver", 2);
if(!present("mace")) {
new(ITEM+"mace.c")->move(this_object());
force_me("wield mace in left hand");
}
}
