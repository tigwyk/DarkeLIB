/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway comes to an abrupt halt, with solid rock on three 
   sides of the corridor.  The floor slopes downward slightly, making 
   way for a set of stairs that run down into the lower levels of the 
   catacombs.  The steps themselves are carved out of the rock that 
   comprises the catacombs.
   
 0--@
        down
        
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"stairs", "staircase", "steps"}):
        "These stairs go down to the third level of the catacombs.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac146",
                "down": PATH+"catac200",
                ]) );
}
