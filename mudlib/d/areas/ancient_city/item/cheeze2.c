
#include <std.h>

inherit "/std/food";

void create() {
        ::create();
set_name("cheeze");
set_id( ({"cheeze"}) );
set_short("A small piece of cheeze");
set_long("A slice of cheeze, the size of a your palm, it is so small that
you can hardly notice it.");
        set_weight(3);
        set_strength(40);
        set_float_value(0.99);
        return;
}

