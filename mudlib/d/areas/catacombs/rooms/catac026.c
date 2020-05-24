/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This is another narrow passageway of the catacombs.  You are forced 
   to duck your head occasionally, in order to avoid from hurting 
   yourself on the stalactites.  You hear the clanging of metal to the 
   southwest.   
       
    @--0
   /
  0    
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "You hear the clanging of metal.");
   set_items( ([
                ({"stalactite", "stalactites"}):
     "The stalactites are very long and hang almost to the floor in places.",
                ]) );
   set_exits( ([
                "east": PATH+"catac028",
                "southwest": PATH"catac025",
                ]) );
}
