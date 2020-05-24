#include <std.h>
inherit "/std/armour";

void create() {
	::create();
       set_name("A pair of sandals");
       set("id", ({"pair", "shoes", "sandals"}) );
       set("short", "A pair of leather sandals");
	set("long",
"These sandals may protect your feet during long journeys, or just "
"from walking over tiny rocks."
	);
	set_type("armor");
       set_ac(7);
        set_limbs( ({ "left foot", "right foot"
          }) );
       set_value(40);
       set_weight(30);
        set_material("leather");
}
