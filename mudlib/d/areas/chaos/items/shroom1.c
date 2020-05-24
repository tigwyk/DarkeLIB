#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("shroom");
	set_id( ({"shroom", "mushroom"}) );
	set_short("A large red squatty mushroom");
	set_long("A large sized mushroom about the size of a melon, it is so large that you can hardly get a grip on it.");
	set_weight(30);
	set_strength(90);
	set_float_value(0.90);
	return;
}
