
#include "../ruins.h"
inherit "/std/weapon";

        create() {
        ::create();
        set_ac(1);
        set("id", ({"sword", "sword"}) );
        set_short("sword");
        set_long("a very strong sword.");
        set_type("blade");
        set_quality(2000);
        set_weight(40);
        set_property("no decay",10);
        set_value(55);
        set_property("decay", 1000);
set_wc(12, "cutting");
 set_verb("slices");
set_hit_bonus(1000); }

