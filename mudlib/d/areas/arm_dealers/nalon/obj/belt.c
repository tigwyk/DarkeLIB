#include <std.h>
inherit "/std/armour";

void create() {
	::create();
      set_name("monk belt");
       set("id", ({"leather", "belt", "monk belt", "leather belt", "leather monk belt"}) );
       set("short", "A leather monk belt");
	set("long",
"The leather belt is very soft from years of wear. The owner must "
"be very fond of it."
    );
        set_type("belt");
       set_ac(10);
        set_limbs( ({ "torso" }) );
        set_value(40);
        set_weight(10);
        set_material("leather");
}
