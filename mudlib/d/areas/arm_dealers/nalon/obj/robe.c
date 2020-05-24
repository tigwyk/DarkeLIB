#include <std.h>
inherit "/std/armour";

void create() {
	::create();
       set_name("A monk robe");
       set("id", ({"robe", "monk robe", "hooded"}) );
        set("short", "A monk robe");
	set("long",
"This is a long hooded robe, the traditional monk's attire. "
	);
        set_type("robe");
        set_ac(10);
        set_limbs( ({ "torso", "left arm", "right arm", "left leg",
                "right leg", "head"}) );
	set_value(400);
	set_weight(100);
        set_material("/misc/cloth");
}
