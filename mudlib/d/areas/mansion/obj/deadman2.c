// dead man 2

#include "mansion.h"

inherit OBJECT;

void create() {
  ::create();
    set_name("mess");
    set_id( ({ "man" }) );
    set_short("a quiet man");
    set_long("The reason this man is so quiet is because he is as dead "+
    "as a door nail.  He lies slumped against the wall, rib cage "+
    "exposed to the beasts that must have pecked him to his demise.  "+
    "He seems to have written something on the wall with his own blood.");
    set_weight(9999);
    set_value(0);
}
