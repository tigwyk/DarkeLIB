//  Wizard:  Khojem
//  captain's desk
//  desk.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("captain's desk");
    set_id( ({ "desk", "captain's desk" }));
    set_short("the captain's desk");
    set_long("The captain's desk is made of a strong metal.  Its desktop "+
      "is scratched and worn from repeated use.  It is bound by strong "+
      "metal buckels at the corners and looks very heavy."
    );
    set_value(100);
    set_weight(5000);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
    set_key("captains_key2");
    set_trap_level(10);
    obj=new("/d/khojem/nomad/obj/diary");
    obj->move(this_object());
    obj=new("std/obj/coins");
    obj->set_money("gold",(random(10)+5));
    obj->move(this_object());
    toggle_closed();
    set_lock("locked");
    set_lock_level(18);
    set_trap_func("/wizards/diewarzau/obj/misc/trap_func","fire_trap");
    set_trap_level(16);
    return;
}

