#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("shroom");
	set_id( ({"shroom", "mushroom"}) );
	set_short("A pudgy purple mushroom");
	set_long("A pudgy purple mushroom, about the size of a pear, it's proportions of head and stem are extremely strange.");
	set_weight(10);
	set_strength(25);
	set_float_value(0.70);
	return;
}
