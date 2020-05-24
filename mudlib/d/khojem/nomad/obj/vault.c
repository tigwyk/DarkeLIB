//  Wizard:  Khojem
//  chief's vault
//  vault.c
 
#include <std.h>

inherit "/std/bag_logic";

void create() {
  object obj;
  ::create();
    set_name("chief's vault");
    set_id( ({ "vault", "chief's vault", "safe" }));
    set_short("a small, square vault");
    set_long("Chief Moped's vault is constructed of a strong metal.  It is a "+
      "small box with a hinged door.  It looks very heavy and scratched from "+
      "years of travel."
    );
    set_value(100);
    set_weight(7000);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
    set_key("chief moped's key");
    obj=new("std/obj/coins");
    obj->set_money("gold",(random(100)+400));
    obj->move(this_object());
    obj=new("/d/khojem/nomad/obj/sapphire");
    obj->move(this_object());
    return;
}
