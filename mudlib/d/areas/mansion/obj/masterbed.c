// master bed

#include "mansion.h"

inherit OBJECT;

void create() {
  ::create();
    set_name("master bed");
    set_id( ({ "bed" }) );
    set_short("a huge bed");
    set_long("This giant bed is fit for a king.");
    set_weight(9999);
    set_value(0);
}
