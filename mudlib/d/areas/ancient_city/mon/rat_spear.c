
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
        set_name("rat");
        set_id("rat");
        set_short("[2]rat-man guard");
        set_long("A rat-man from the Grey rat clan.");
        set_level(2);
set_body_type("rat");
        set("race", "rat");
        set_skill("melee", 15);
        set_wielding_limbs( ({"left hand", "right hand"}) );
        set_gender("male");
        set_skill("dodge", 5);
        set_skill("attack", 10);
        set_skill("block", 10);
        set_alignment(-10);
if(!present("spear")) {
new(ITEM+"spear.c")->move(this_object());
force_me("wield spear in left hand and right hand"); }
set_languages( ({"common"}) );
set_speech(3, "common", ({"OK!! That's it you want some don't you!", "I've
killed more things then you will ever!! HAHAHAHA!!!"}) );
set_achats(15, ({"The rat-man child flails his spear around his haed.",
"The rat-man tries to stab you, but misses you totaly.", "The rat-man trips
over his tail, falling falt on his face."}));
set_money("silver", 50);
}

