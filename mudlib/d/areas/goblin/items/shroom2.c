#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("shroom");
	set_id( ({"shroom", "mushroom"}) );
	set_short("A small moss covered mushroom");
	set_long("A small mushroom, it is about the size of a tangerine.  It's entire body is covered with a strange glowing aura.");
	set_weight(3);
	set_strength(40);
	set_float_value(0.99);
	return;
}
