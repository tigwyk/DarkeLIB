// dead man

#include "mansion.h"

inherit OBJECT;

void create() {
  ::create();
    set_name("mess");
    set_id( ({ "man" }) );
    set_short("a half-eaten man");
    set_long("You see the disgusting remains of an elf ranger.  "+
    "Fresh blood covers the floor around it, and teeth marks line "+
    "it's mangled body, nearly torn in half.  Entrails lie strewn "+
    "about at your feet.");
    set_weight(9999);
    set_value(0);
}
