//      From Maxwell's Underground mudlib
//          8th Room of Dwarf Mining Zone

#include "under.h"
inherit TRAP;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long",@ext 
You are standing in a damp mine tunnel somewhere within the 
Under'Drin Mining complex. Water slowly rolls down the walls in 
little streams, soaking the moldy straw that is lining the passage. 
You can see faint seams of mineral deposits in the walls." 
      0  
     /   
    @
    |
    0       
ext);
    set_exits( ({ UNDER+"dm6", UNDER+"dm9b" }),
      ({ "northeast", "south" })
    );
    set_items( ([
       "water" : "There must be an underground spring nearby.",
      ]) );
//Trap Code
    set_pre_exit_functions( ({"south" }), ({"trap_check"}) );
    trap_active = "disarmed";
    trap_level  = 13;
    trap_type = "Poison Dart";
    trapped_exit = "straw";
    sister_trap = (UNDER+"dm9b");
    safe_players = ({});
}

