
#include <std.h>

inherit "/std/food";

void create() {
        ::create();
set_name("cheeze");
set_id( ({"cheeze"}) );
set_short("A large piece of cheeze");
set_long("A cube of cheeze, the size of a small bolder, it is so large that
it is hard to put into your month.");
        set_weight(3);
        set_strength(90);
        set_float_value(0.99);
        return;
}

