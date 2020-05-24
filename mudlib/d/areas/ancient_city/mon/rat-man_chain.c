
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
set_name("rat");
set_id( ({"rat", "frantic"}) );
set_short("[3]Frantic rat-man");
        set_long("An estatic gibbering rat-man, who is impervious to pain,
and is largely unaware of his enviroment.  He is very strong, and has
immensely no feeling to pain.  He carries a hug ball on a chain, a weapon
so large that is would be impossible for any rat-man to wield, but because
of the fanatic strength that the rat-man has, he is abul to not only wield
the weapon but also to use it with great skill.");
set_level(3);
set_body_type("rat");
        set("race", "rat");
        set_skill("melee", 20);
        set_wielding_limbs( ({"left hand", "right hand"}) );
        set_gender("male");
        set_skill("attack", 10);
        set_alignment(-10);
if(!present("chain")) {
new(ITEM+"ball_chain")->move(this_object());
force_me("wield chain in left hand and right hand"); }
set_languages( ({"common"}) );
        set_speech(3, "common", ({"AHHHHH!!", "URRGGG!", "Unnngggghh!",
"AAAAiiieee!"}) );
        set_achats(20, ({"The rat-man mumbles something unknown to anyone,
not ever other rat-man", "The rat-man scurries around the room like rat
after cheeze.", "The rat-man jumps up and down psychotically."}));
set_money("silver", 100);
}


