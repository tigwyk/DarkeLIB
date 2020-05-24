#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("snotling");
        set_id(({ "snotling" }) );
	set_level(1);
	set_short("[1]dark green snotling");
	set_long("A smaller goblin, with minimal intelligence.  He is here to harvest mushrooms for his cousins to eat.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 5);
	set_wielding_limbs( ({"left hand"}) );
	set_skill("dodge", 3);
	set_skill("block", 3);
	set_stats("strength", 10);
	set_stats("intelligence", 10);
	set_skill("parry", 10);
	set_stats("constitution", 10);
	set_stats("wisdom", 5);
	set_stats("dexterity", 10);
	set_stats("charisma", -10);
	set_skill("blade", 10);
	set_skill("attack", 5);
	set_alignment(-10);
if(!present("knife")) {
new(ITEM+"knife.c")->move(this_object());
force_me("wield knife in left hand");
set_languages( ({"common"}) );
        set_speech(20, "common", ({"Ooooww! dat urts!", "Stiy buc! Er aye vil pummol ye vit my shrooms!", "Ye stink!"}), 1);
	set_money("silver", 2);
}
}
