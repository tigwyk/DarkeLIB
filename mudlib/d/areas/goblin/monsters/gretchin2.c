inherit "/std/monster";
#include "../goblin.h"


create() {
	::create();
	set_id("snotling");
	set_level(1);
	set_short("[1]small green gretchin");
	set_long("A smaller goblin, with minimal intelligence.  He is here to harvest mushrooms for his cousins to eat.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 10);
	set_wielding_limbs( ({"left hand"}) );
	set_overall_ac(2);
	set_skill("dodge", 5);
	set_skill("block", 10);
	set_alignment(-10);
if (!present("knife")) {
new(ITEM+"knife.c")->move(this_object());
force_me("wield knife in left hand");
set_languages( ({"common"}) );
	set_speech(25, "common", ({"Ooowww! That hurts!", "Stay back! Or I will  pummel you with my mushrooms!", "You stink!"}),1 );
	set_money("copper", 100);
}
}
