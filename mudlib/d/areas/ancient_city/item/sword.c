
#include "../ruins.h"
inherit "/std/weapon";

        create() {
        ::create();
        set_ac(1);
set("id", ({"sword", "fine sword"}) );
set_short("fine sword");
set_long("A crumbly sword.  Used mainly by the rat-man.");
        set_type("blade");
set_quality(3);
        set_weight(40);
        set_value(55);
        set_property("decay", 100);
        set_wc(12, "cutting");
        set_verb("rip");
        set_hit_bonus(10);
}

