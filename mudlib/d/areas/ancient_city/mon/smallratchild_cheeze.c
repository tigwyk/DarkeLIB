
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
        set_name("rat-man child");
set_id( ({"rat", "child"}) );
        set_short("[1]grey rat-man child");
        set_long("A rat-man child is a young rat-man, he is looking for
cheeze to eat.");
        set_level(1);
set_body_type("rat");
set("race", "rat");
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
set_languages( ({"common"}) );
set_speech(3, "common", ({"I need cheeze, I said I NEED CHEEZE, GIVE ME
CHEEZE!!", "gotta find cheeze, more cheeze.", "CHEEZE!!"}) );
set_money("gold", 1);


switch(random(3)){
case 0:new(ITEM+"cheeze1.c")->move(this_object());
        break;
case 1:new(ITEM+"cheeze2.c")->move(this_object());
        break;
case 2:new(ITEM+"cheeze3.c")->move(this_object());
        break;
}
}

