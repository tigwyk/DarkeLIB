#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("rabbits foot");
	set_id( ({"foot", "rabbits foot"}) );
	set_short("A small furry rabbits foot");
	set_long("A small rabbits foot, considered by some to be a good luck charm.  It is attached to a small chain at the end for you to put into a key chain.");
	set_weight(5);
	set_strength(30);
	set_float_value(0.70);
	return;
}
