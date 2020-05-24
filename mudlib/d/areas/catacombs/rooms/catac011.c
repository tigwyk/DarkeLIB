/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "A Large Chamber in Some Catacombs");
   set("long",@ext
   This is the eastern extremity of the large chamber.  The wall here is 
   nondescript and featureless, and cold to the touch.  There is a small 
   passageway to the northeast that leads into darkness.
  0   0  
   \ /   
 0--@
     \
      0  
ext);
   set_smell("default", "The air smells clean.");
   set_listen("default", "You hear rattling to the northeast.");
   set_items( ([
                "wall": "The face of the wall is featureless.",
                ]) );
   set_exits( ([
                "west": PATH+"catac008",
                "southeast": PATH+"catac014",
                "northwest": PATH+"catac010",
                "northeast": PATH+"catac017",
                ]) );
}
