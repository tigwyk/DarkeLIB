// sculpture

#include "mansion.h"

inherit OBJECT;

void create() {
  ::create();
    set_name("sculpture");
    set_id( ({ "sculpture" }) );
    set_short("a strange sculpture");
    set_long("This sculpture is made out of some strange blue rock.  "+
    "As far as you can tell, it appears to be of a man and a woman "+
    "holding up a vase.");
    set_weight(9999);
    set_value(0);
}
