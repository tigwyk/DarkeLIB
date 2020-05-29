//      From Maxwell's Underground mudlib
//          Entrance Room for Dwarf Mining Zone


#include "under.h"

inherit TRAP;

//int safe;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short",
      "You are standing at the entrance to the Dwarf mine."
       );
    set("long", 
"You are standing in the entrance tunnel to the Under'Drin Mines. "
"The smooth tunnel walls look like they were carved out by dedicated "
"workers. There are thick support timbers evenly spaced along the "
"tunnel walls and across the ceiling.\nThe floor has deep ruts cut into "
"it. The loaded mining carts that pass through here must be very heavy."
       );
    set_exits( ({ UNDER+"dm1",UNDER+"dmc" }), ({ "north", "south" }) );

    set_pre_exit_functions(({"north" }), ({"trap_check"}) );

//Trap Code Variable
    trap_active = "armed";
    trap_type = "Explosive";
    trap_level = 13;
    trapped_exit = "ruts";
    sister_trap = (UNDER+"dm1");
    safe_players = ({});
}
int init() {
    ::init();

    if(this_player()->is_player() || this_player()->is_pet()) return 1;
    else {
     this_player()->force_me("north");
     return 1;
     }
  
}
void reset(){
   ::reset();
   trap_active = "armed";
}


