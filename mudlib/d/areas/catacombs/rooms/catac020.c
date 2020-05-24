/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   You are standing in the northeastern corner of a huge chamber of the 
   catacombs.  The ceiling is far above your head - the tallest storm 
   giant would have ample room to move around.  Torches line the walls, 
   providing ample light.  Large boulders are strewn all over the 
   ground, and small rocks abound.  There is an exit to the northeast 
   that leads into darkness.
      0  
     /   
 0--@
   /|
  0 0  
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                ({"boulder", "boulders"}):
    "There are several large boulders in the chamber.",
                ({"rock", "rocks"}):
    "There are rocks of every size and shape strewn all over the floor.",
                "ceiling":
    "The ceiling is far above your head, well out of reach.",
                "torches":
    "The torches are firmly affixed to the walls and provide a little light.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac019",
                "west": PATH+"catac022",
                "south": PATH+"catac021",
                "southwest": PATH+"catac023",
                ]) );
}
