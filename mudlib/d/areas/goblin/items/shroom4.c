#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("shroom");
	set_id( ({"shroom", "mushroom"}) );
	set_short("A strangely malformed mushroom");
	set_long("A strange looking mushroom, its body is contorted in all sorts of miscreant ways.");
	set_weight(5);
	set_strength(40);
	set_float_value(0.80);
	return;
}
