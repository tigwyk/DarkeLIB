
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
set_name("rat-man child");
set_id( ({"rat", "child"}) );
set_short("[1]light grey rat-man child");
set_long("A rat-man child is a young rat-man, he is looking for cheeze to
eat.");
        set_level(1);
set_body_type("rat");
set("race", "rat");
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
new(ITEM+"furbag.c")->move(this_object());
}
set_languages( ({"common"}) );
set_speech(3, "common", ({"I need cheeze, I said I NEED CHEEZE, GIVE ME
CHEEZE!!", "gotta find cheeze, more cheeze.", "CHEEZE!!"}) );
        set_money("gold", 1);
}

