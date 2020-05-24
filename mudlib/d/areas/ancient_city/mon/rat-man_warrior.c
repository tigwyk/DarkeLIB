
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
set_name("rat-man");
set_id( ({"rat","rat-man warrior","warrior"}) );
set_short("[2]rat-man warrior");
set_long("A rat-man from the Grey rat clan.");
        set_level(2);
set_body_type("rat");
 set("race", "rat");
        set_skill("melee", 15);
        set_wielding_limbs( ({"left hand"}) );
        set_gender("male");
        set_skill("dodge", 5);
        set_skill("attack", 10);
        set_skill("block", 10);
        set_alignment(-10);
if(!present("sword")) {
new(ITEM+"sword.c")->move(this_object());
force_me("wield sword in left hand"); }
new(ITEM+"shield.c")->move(this_object());
force_me("wear shield");
set_languages( ({"common"}) );
set_money("silver ", 50);
}
