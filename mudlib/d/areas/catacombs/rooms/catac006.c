/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This narrow passageway connects two of the larger chambers of the 
   catacombs.  The tunnel runs to the north and southwest from here.  
   All is dark in both directions.
    0   
    |   
    @
   /
  0    
ext);
   set_smell("default", "You smell something foul.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                "tunnel":"The narrow passageway runs north-southwest.",
                ]) );
   set_exits( ([
                "north": PATH+"catac008",
                "southwest": PATH+"catac004",
                ]) );
}
