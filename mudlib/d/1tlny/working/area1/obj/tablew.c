// dining table w

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("table");
    set_id( ({ "table" }) );
    set_short("a dining table");
    set_long("You see one end of a long dining room table.  Many "+
    "chairs lie overturned here, and part of the table has been "+
    "crushed by a large statue from above.");
    set_weight(9999);
    set_value(0);
}
