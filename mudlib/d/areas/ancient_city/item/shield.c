
#include "../ruins.h"
inherit "/std/armour";

   create() {
        ::create();
        set_name("wooden shield");
set("id", ({"shield", "fine shield"}) );
        set("short", "a wooden shield");
set("long", "A wooden shield, common of the rat-man that inhabit the
area.");
        set_type("shield");
        set_ac(5);
        set_weight(30);
        set_limbs(({({"right hand", "left hand", "first branch", "second
branch",
"third branch", "fourth branch",
})}));
        set_value(40);
        set_weight(20);
}

