#include <std.h>
#include "nevin.h"

inherit MONSTER;

void create(){
	::create();
	set_name("bandit leader");
	set_id( ({"bandit", "leader"}) );
	set_level(5);
	set("short", "[5]Bandit leader");
	set("long",
		"As you approach, he quickly stuffs their money into a bag and stands up to meet you in battle."
	);
	set("race", "human");
	set_gender("male");
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_moving(0);
	set_skill("blade", 60);
	set_skill("knife", 70);
	set_class("fighter");
	set("aggressive", 0);
	set_wimpy(30);
	add_money("gold", 10 + random(40));
	set_alignment(-200);
	set_languages( ({"common"}) );
	set_lang_prof("common", 8);
	new(WEAP+"short_sword.c")->
		move(this_object());
	force_me("wield sword in right hand");
}
