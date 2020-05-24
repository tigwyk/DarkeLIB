#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
int change_name;
	::create();
	set_name("squig");
	set_id( ({"squig"}));
	set_level(2);
change_name=random(2);
if(change_name)  set_short("[2]A malicious green cave squig");
else set_short("[2]purple headed cave squig");

	set("race", "plant");
	set_long("A cave squig, a creature that is part fungus part flesh.  They have tough ball shaped bodies and clumsy taloned feet.  Cave squigs have hug gaping mouths thronged with slashing teeth.");
	set_body_type("quadruped");

	set_skill("melee", 20);
	set_skill("dodge", 30);
	set_stats("strength", 20);
	set_property("melee damage", (["crushing" : 40]) );
//         set_moving(3);
//         set_speed(60);
    set_wimpy(15);
switch(random(5)) {
case 0:new(ITEM+"shroom.c")->move(this_object());
break;
case 1:new(ITEM+"shroom1.c")->move(this_object());
break;
case 2:new(ITEM+"shroom2.c")->move(this_object());
break;
case 3:new(ITEM+"shroom3.c")->move(this_object());
break;
case 4:new(ITEM+"shroom4.c")->move(this_object());
}

}
