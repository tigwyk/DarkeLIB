#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("snotling");
	set_id("snotling");
	set_level(1);
	set_short("[1]Light green snotling");
	set_long("A distant cousin of the goblin, he is a slave only to pick mushrooms and do nothing else.");

	set_body_type("human");
	set("race", "goblin");
	set_wielding_limbs( ({"left hand"}) );
	set_skill("melee", 10);
	set_skill("parry", 10);
	set_skill("knife", 10);
	set_skill("attack", 10);
	set_stats("strength", 20);
	set_skill("dodge", 15);
	set_stats("intelligence", 10);
	set_stats("dexterity", 20);
	set_stats("constitution", 10);
	set_stats("charisma", -10);
	set_stats("wisdom", 10);
	set_gender("male");
	set_alignment(-10);
if(!present("bag")) {
new(ITEM+"nettedbag.c")->move(this_object());
}
set_languages( ({"common"}) );
	set_speech(3, "common", ({"Hi, ho, hi, ho off to shooms we go!", "gotta pick shooms, more shooms.", "Shooms!"}), 1 );
	set_money("silver", 1);
}
