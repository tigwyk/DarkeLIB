
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("oil");
    set_id( ({ "oil" }) );
    set_short("A pouch of oil");
    set_long("A small worn pouch full of oil.\n");
    set_weight(20);
    set_float_value(15);
    set_property("no save", 1);
}
