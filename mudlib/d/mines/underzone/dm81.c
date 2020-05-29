//      From Maxwell's Underground mudlib
//        81st Room of Dwarf Mining Zone


#include "under.h"
inherit TRAP;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a long tunnel. The walls appear "
"to have been mined recently. The floor is "
"covered with a large amount of straw and other debris.");
    set("long", 
"You are standing in a long tunnel somewhere in the Mining Complex. "
"The cold walls stretch off in front of you, filled with pits and "
"fresh cracks from the recent mining of the Dwarves.\nThe floor is "
"covered with a large amount of straw and other debris\n");
    set_exits( ({ UNDER+"dm71",UNDER+"dm82"}),
      ({ "west","north" })
    );
//Trap Code Variable
    set_pre_exit_functions(({"north" }), ({"trap_check"}) );
    trap_active = "disarmed";
    trap_type = "Hot Gas";
    trap_level = 13;
    trapped_exit = "straw";
    sister_trap = (UNDER+"dm82");
    safe_players = ({});
}




