// small bed

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("bed");
    set_id( ({ "bed" }) );
    set_short("a small bed");
    set_long("You see a neatly made bed set against the wall.");
    set_weight(9999);
    set_value(0);
}
