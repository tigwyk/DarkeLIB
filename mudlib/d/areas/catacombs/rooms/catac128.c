/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway heads northeast for a short distance before coming 
   to a sudden end.  The rock walls are just a few feet apart, 
   the passageway coming to an end at a rounded wall.  The corridor 
   runs back to the southwest, where the rest of the catacombs lie.  
   There appears to be a somewhat large crack in the northern wall.
    0   
    |   
    @
   /
  0    
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_search("default", "You could easily fit through the crack in the northern wall.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ({"northern wall", "crack"}):
        "You could easily fit through the crack in the northern wall.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac127",
                "north": PATH+"catac147",
                ]) );
   set_invis_exits( ({"north"}) );
}
