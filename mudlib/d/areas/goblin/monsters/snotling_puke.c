#include <std.h>
#include "../goblin.h"

inherit MONSTER;


create() {
	::create();
	set_name("snotling");
	set_id("snotling");
	set_level(1);
	set_short("[1]lime green snotling");
	set_long("A distant cousin of the goblin, he is a slave only to pick mushrooms and do nothing else.");

	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 5);
	set_skill("parry", 10);
	set_skill("blade", 10);
	set_wielding_limbs( ({"left hand"}) );
	set_stats("dexterity", 15);
	set_stats("constitution", 10);
	set_stats("wisdom", 10);
	set_stats("strength", 10);
	set_stats("intelligence", 10);
	set_gender("male");
	set_skill("dodge", 3);
	set_skill("attack", 5);
	set_alignment(-10);
set_languages( ({"goblin"}) );
	set_speech(3, "goblin", ({"Burrrrp!", "I fel lik im guna chuc!", "betta stay buc, i'm gunna blow!"}), 1 );
	set_money("gold", 2);

switch(random(5)){
case 0:new(ITEM+"shroom.c")->move(this_object());
	break;
case 1:new(ITEM+"shroom1.c")->move(this_object());
	break;
case 2:new(ITEM+"shroom2.c")->move(this_object());
	break;
case 3:new(ITEM+"shroom3.c")->move(this_object());
	break;
case 4:new(ITEM+"shroom4.c")->move(this_object());
	break;
}
}
