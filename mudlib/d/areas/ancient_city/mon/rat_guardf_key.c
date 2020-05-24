
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
        ::create();
        set_name("rat-man");
        set_id( ({"rat", "rat-man champion", "champion"}) );
set_short("[6]oversized rat-man champion");
        set_long("This is one of the rat-man champions, his minscule size
is a disapointment to the symbol in his clan.  He wields a large axe that
would easily topple any normal rat-man trying to wield it.");
set_level(6);
set_body_type("rat");
        set("race", "rat");
        set_skill("melee", 20);
        set_wielding_limbs( ({"left hand", "right hand"}) );
        set_overall_ac(3);
        set_gender("male");
        set_skill("dodge", 5);
        set_skill("attack", 13);
        set_skill("block", 12);
        set_alignment(-20);
        set_stats("strength", 30);
set_languages( ({"common"}) );
        set_speech(5, "common", ({"He he he...You you won't to die?", "Are
you what they call a challange? He he he!", "More for me to kill? He he
he"}) );
        set_achats(20, ({"The rat-man champion swings his axe down on
you.", "The rat-man champion swings his axe like, well like a rat-man!?!",
"The rat-man champion snickers madly as he paces the hall."}));
        set_money("gold", 6);
if(!present("key")) {
new(ITEM+"guard's_key.c")->move(this_object());
if(!present("axe")) {
new(ITEM+"l_axe.c")->move(this_object());
force_me("wield axe in left hand and right hand");
}
}
}
