
#include "../ruins.h"
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
set_name("demon's key");
set_id( ({ "demon's key", "key" }) );
set_short("demon's key");
set_long("A small, simple metal key unadored with markings.");
set_weight(1);
    set_value(0);
}

