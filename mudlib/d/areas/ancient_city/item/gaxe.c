
#include "../ruins.h"
inherit "/std/weapon";

        create() {
        ::create();
        set_ac(1);
set_name("The axe of grom");
        set("id", ({"axe", "axe of grom", "large axe"}));
        set_short("The axe of Grom");
        set_long("A large maniacal looking axe, its edge is sharpened to a
razors
edge.  The handle of the axe is made out of some arcane material.");
        set_type("two handed blade");
        set_weight(150);
        set_quality(5);
        set_property("no add quality", 1);
        set_property("no decay", 1);
        set_weight(180);
        set_wc(16, "cutting");
        set_verb("slaughter");
        set_hit_bonus(10);
        set_value(300);
}

