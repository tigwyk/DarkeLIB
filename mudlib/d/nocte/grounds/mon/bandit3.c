#include <std.h>
#include "nevin.h"

inherit MONSTER;

create() {
	::create();
	set_name("bandit");
	set("id", ({ "bandit", "_bandit3" }) );
	set_level(2);
	set("short", "[2]A bandit");
	set("long",
		"I wouldn't bother him right now...he seems very intent "
		"on his teeth picking."
	);
	add_money("gold", 10+random(30));
	set_alignment(-100);
	set("race", "human");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(0);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 20);
	set_skill("attack", 20);
	set_skill("knife", 20);
	set_wimpy(20);
	set("aggressive", 0);
	set_lang_prof("Middle-english", 5);
	new(WEAP+"dagger.c")->
		move(this_object());
	force_me("wield dagger in left hand");
}
