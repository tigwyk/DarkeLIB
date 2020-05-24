/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   The passageway continues and forks east and northeast, winding 
   its way through the seemingly endless system of catacombs.  It 
   seems as though no one has walked through here in ages.
      0  
     /   
    @--0
   /
  0    
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([ ]) );
   set_exits( ([
                "northeast": PATH+"catac014",
                "east": PATH+"catac013",
                "southwest": PATH+"catac007",
               ]) );
}
