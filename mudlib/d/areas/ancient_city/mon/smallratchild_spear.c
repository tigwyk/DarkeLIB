
#include "../ruins.h"
#include <std.h>

inherit MONSTER;


create() {
object ob;
        ::create();
set_name("rat-man child");
set_id( ({"rat", "child"}) );
set_short("[1]light grey rat-man child");
set_long("A rat-man child is a young rat-man, he is preparing to for guard
duty.");
set_level(1);
set_body_type("rat");
set("race", "rat");
        set_skill("melee", 5);
set_wielding_limbs( ({"left hand", "right hand"}) );
        set_skill("dodge", 3);
        set_skill("block", 3);
        set_stats("strength", 10);
        set_stats("intelligence", 10);
        set_skill("parry", 10);
        set_stats("constitution", 10);
        set_stats("wisdom", 5);
        set_stats("dexterity", 10);
        set_stats("charisma", -10);
        set_skill("blade", 10);
        set_skill("attack", 5);
        set_alignment(-10);
        set_wielding_limbs( ({"left hand", "right hand"}) );
ob = new(ITEM+"spear.c");
ob->move(this_object());
force_me("wield spear in left hand and right hand");
set_languages( ({"common"}) );
set_speech(3, "common", ({"OK!! That's it you want some don't you!", "I've
killed more things then you will ever!! HAHAHAHA!!!"}) ); 
set_achats(15, ({"The rat-man child flails his spear around his haed.",
"The rat-man tries to stab you, but misses you totaly.", "The rat-man trips
over his tail, falling falt on his face."}));
     set_money("gold", 2);
}

