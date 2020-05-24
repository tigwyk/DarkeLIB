#include <std.h>
inherit "/std/armour";

void create() {
	::create();
     set_name("gloves");
       set("id", ({"gardening", "gardening gloves", "gloves"}) );
      set("short", "A pair of gardening gloves");
	set("long",
"These gloves provide the wearer with a little protection from the "
"poisonous, and beautifull, plants they tend to."
	);
	set_type("armor");
       set_ac(10);
       set_limbs( ({ "right hand",
                "left hand"}) );
       set_value(100);
        set_weight(30);
	set_material("cloth");
}
