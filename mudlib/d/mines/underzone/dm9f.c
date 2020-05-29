//      From Maxwell's Underground mudlib
//        9F Room of Dwarf Mining Zone

#include "under.h"
inherit TRAP;

string who,name;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long", 
"You are standing in a large connection chamber. The solid stone walls "
"stretch to the north and south here.\nA small alcove is to the west, "
"framed by serveral thick support beams. The beams are fitted to the "
"rock wall with bolts that must be the size of a dwarf's hand.");
    set_exits( ({ UNDER+"dm9b",UNDER+"dm9c",UNDER+"dm9e",UNDER+"dm9h"
               ,UNDER+"dm9i",UNDER+"dm10" }),
      ({ "northwest","north","west","southwest","south","alcove" }));
    set_items( ([
      "bolts" : "The thick bolts must have been very hard to put in place.",
      ]) );
//Trap Code Variable
    set_pre_exit_functions(({"alcove" }), ({"trap_check"}) );
    trap_active = "armed";
    trap_type = "Hot Gas";
    trap_level = 13;
    trapped_exit = "beams";
    safe_players = ({});

}
void reset(){
   ::reset();
   trap_active = "armed";
}


