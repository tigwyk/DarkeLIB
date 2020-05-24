/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Forest Clearing");
   set("long",@ext
   This is a small clearing in the forest.  In the center of the 
   clearing stands a crumbling building, which appears to be a small 
   crypt.  The vegetation surrounding the crypt is dead and twisted.  
   From outside the building, it seems that all is quiet inside.  
       
        crypt   
    @
        out
       
ext);
   set_smell("default", "The smell of pine trees hangs in the air.");
   set_listen("default", "The wind blows coldly.");
   set_items( ([
                ({"crypt", "buidling"}):
      "The crypt is in poor condition and beckons you to explore.",
                ({"vegetation", "plants"}):
      "All the plants here are dead and twisted.",
                "trees":
      "The pine trees surround the clearing.",
              ]) );
   set_exits( ([ "crypt":PATH+"catac000",
                 "out":"/d/damned/virtual/room_4_23.world",
              ]) );
}
 
