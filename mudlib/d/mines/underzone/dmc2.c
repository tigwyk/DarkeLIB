//      From Maxwell's Underground mudlib
//        2nd Room of Dwarf Mining/Crypt Zone

#include <std.h>
#include "under.h"
inherit TRAP;

string who,name;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large room at the base of a spiral "
"staicase. There is a large archway to the east.");
    set("long", "You are standing in a large room at the base of the "
"spiral staircase. The stone floor is rough and stained from the passage "
"of time. You sense that you are in a sacred place. Perhaps you should "
"not continue further.\n");
    set_exits( ({ UNDER+"dm43",UNDER+"dmc3"}),
      ({ "up","arch" }));
    set_items( ([
      "wall" :"The old stone walls surround you on all sides.",
      "walls" : "The old stone walls surround you on all sides.",
      "stone wall" : "The old stone walls surround you on all sides.",
      "stone walls" : "The old stone walls surround you on all sides.",]));
    set_smell("default", "You can smell the foul stench of decay and "
         "mold.");
    set_listen("default","You can hear a strange crackling sound coming "
     "from the arch.");
//Trap Code Variable
    set_pre_exit_functions(({"arch" }), ({"trap_check"}) );
    trap_active = "armed";
    trap_type = "Explosive";
    trap_level = 13;
    trapped_exit = "arch";
    safe_players = ({});

}
void reset(){
   ::reset();
   trap_active = "armed";
}


