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
   yourself on the stalactites.  You ears are filled with banging and 
   rattling. 
    0 0  
    |/   
    @
   /
  0    
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is loud rattling and to the northeast.");
   set_items( ([ ]) );
   set_exits( ([
                "north": PATH+"catac029",
                "northeast": PATH+"catac031",
                "southwest": PATH+"catac028",
                ]) );
}
