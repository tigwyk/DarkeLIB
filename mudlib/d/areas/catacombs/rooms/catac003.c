/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This small part of the catacombs stands south of the entrance.  The 
   walls are covered with thick moss and the air is thick with dampness.  
   All is quiet here.  Darkness lies to the room to the south.   
    0   
    |   
    @
    |
    0
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "The room is silent.");
   set_items( ([
                "south":
          "The room to the south is dark.",
                "moss":
          "The dark green moss hangs in clumps on the wall.",
               ]) );
   set_exits( ([
                "south": PATH+"catac005",
                "north": PATH+"catac001",
               ]) );
}
