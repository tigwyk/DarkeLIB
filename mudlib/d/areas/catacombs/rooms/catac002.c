/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This large room lies north of the entrance of the catacombs.  To the 
   south you see very faint sunlight, while to the east there is total 
   darkness.  A thin layer of dust covers the floor.
  
    @--0
    |
    0   
ext);
   set_smell("default", "You smell something foul.");
   set_listen("default", "You hear the scraping of shoes on stone nearby.");
   set_items( ([
                "south":
       "Heading south will take you to the entrance.",
                "east":
       "There is darkness to the east.",
                "dust":
       "There is nothing special about the dust.",
               ]) );
   set_exits( ([
                "south": PATH+"catac001",
                "east": PATH+"catac004",
               ]) );
}
 
void reset() {
   if(!present("zombie"))
      new(MON_PATH+"zombie")->move(this_object());
}
