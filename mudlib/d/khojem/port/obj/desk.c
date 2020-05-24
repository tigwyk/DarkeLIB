//  Wizard:  Khojem
//  earl's desk
//  desk.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("desk");
    set_id( ({ "dest", "mahogany desk" }));
    set_short("mahogany desk");
    set_long("The mahogany desk is highly polished and very large.");
    set_value(1);
    set_weight(99999);
    set_max_internal_encumbrance(600);
    set_possible_to_close(1);
    obj=new("/d/khojem/port/obj/harbor_map");
    obj->move(this_object());
    obj=new("std/obj/coins");
    obj->set_money("gold",(random(60)+5));
    obj->move(this_object());
    toggle_closed();
    set_key("earl_desk_key");
    set_lock("locked");
    set_lock_level(19);
    set_trap_func("/wizards/diewarzau/obj/misc/trap_func","fire_trap");
    set_trap_level(19);    
    return;
}

