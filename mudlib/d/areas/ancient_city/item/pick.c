
#include "../ruins.h"
inherit "/std/weapon";

        create() {
        ::create();
        set_ac(0);
set("id", ({"pick", "pick axe", "axe"}) );
set_short("rusted pick axe");
set_long("A pick axe used by rat childern.");
        set_type("knife");
        set_quality(2);
        set_weight(15);
        set_property("decay", 200);
        set_value(30);
        set_wc(7, "impaling");
        set_verb("poke");
        set_hit_bonus(10);
}
