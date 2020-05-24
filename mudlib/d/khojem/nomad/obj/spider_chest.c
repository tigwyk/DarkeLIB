//  Wizard:  Khojem
//  spider chest
//  spider_chest.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("sturdy wooden chest");
    set_id( ({ "chest", "wooden chest", "sturdy wooden chest" }));
    set_short("a sturdy, wooden chest");
    set_long("The small chest is built from a strong hardwood and "+
      "brass plating to reinforce the joints.  The chest has "
      "rested here for some time undisturbed judging by the "+
      "accumulation of dust over the years.");
    set_value(140);
    set_weight(1000);
    set_short("A small chest");
    set_max_internal_encumbrance(200);
    set_possible_to_close(1);
    set_key("key_that_does_not_exist");
    set_property("magic hold",40);
    obj=new("/d/khojem/nomad/weapon/ob_dirk");
    obj->move(this_object());
    return;
}
