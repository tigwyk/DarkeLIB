// dining table e

#include "mansion.h"

inherit OBJECT;

void create() {
  ::create();
    set_name("table");
    set_id( ({ "table" }) );
    set_short("a dining table");
    set_long("You see one end of a long dining room table.  Chairs "+
    "line each side of the table neatly in place.");
    set_weight(9999);
    set_value(0);
}
