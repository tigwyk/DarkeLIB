//  Wizard:  Khojem
//  warrior locker
//  warrior_locker.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("sturdy locker");
    set_id( ({ "chest", "sturdy locker", "sturdy metal locker", "locker" }));
    set_short("a sturdy, wooden locker");
    set_long("It is a sturdy, metal locker.  Its corners are "+
      "reinforced with heavy, metal studs and wrapped with metal "+
      "strapping.");
    set_value(2000);
    set_weight(3000);
    set_short("A sturdy locker");
    set_max_internal_encumbrance(800);
    set_possible_to_close(1);
    set_key("captains_key");
    set_property("magic hold",80);
    obj=new("/d/damned/virtual/scimitar_6.weapon");
    obj->move(this_object());
    obj=new("/d/damned/virtual/scimitar_6.weapon");
    obj->move(this_object());
    obj=new("/d/damned/virtual/scimitar_6.weapon");
    obj->move(this_object());
    obj=new("/d/khojem/nomad/obj/compass");
    obj->move(this_object());
    toggle_closed();
    set_lock("locked");
    set_lock_level(11);
    set_trap_func("/wizards/diewarzau/obj/misc/trap_func","fire_trap");
    set_trap_level(12);
    return;
}

