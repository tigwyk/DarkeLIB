/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   You are standing in the northwestern corner of a huge chamber of the 
   catacombs.  The ceiling is far above your head - the tallest storm
   giant would have ample room to move around.  Torches line the walls, 
   providing ample light.  Large boulders are strewn all over the 
   ground, and small rocks abound.
 
    @--0
    |\
    0 0  
ext);
   set_smell("default", "The air smells fresh.");
   set_listen("default", "Your footsteps echo loudly in the chamber.");
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
                "southeast": PATH+"catac021",
                "east": PATH+"catac020",
                "south": PATH+"catac023",
                ]) );
}

void reset() {
   object ob;
   ::reset();

   if(!present("skeleton")) {
      ob = new(MON_PATH+"skeleton");
      ob->move(this_object());
   }
}
