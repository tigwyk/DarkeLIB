/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "A Large Chamber in Some Catacombs");
   set("long",@ext 
   This is the northernmost section of the large chamber in this part of 
   the catacombs.  The walls are smooth in most places, while there are 
   a few small cracks here and there.      
       
    @
   /|\
  0 0 0  
ext);
   set_smell("default", "The air has a fresh, clean smell.");
   set_listen("default", "You hear the trickling of water to the southwest.");
   set_items( ([
                ({"wall", "walls"}):
        "The walls are smooth in most places.",
                ({"crack", "cracks"}):
        "Very fine cracks run up and down the wall.",
                ]) );
   set_exits( ([
                "south": PATH+"catac008",
                "southwest": PATH+"catac009",
                "southeast": PATH+"catac011",
                ]) );
}
 
void reset() {
   if(!present("skeleton"))
      new(MON_PATH+"skeleton")->move(this_object());
}
