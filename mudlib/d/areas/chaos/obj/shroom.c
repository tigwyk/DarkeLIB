#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("shroom");
	set_id( ({"shroom", "mushroom"}) );
	set_short("A blue ringed yellow topped mushroom");
	set_long("A medium sized mushroom about the size of an orange, its top is a greenish-yellow in color, while its stem has a blue ring around it.");
	set_weight(5);
	set_strength(30);
	set_float_value(0.70);
	return;
}
