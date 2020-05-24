/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This is a three-way intersection of the catacombs.  Dark passageways 
   lead to the northeast and west, while there is a faint light to the 
   northwest.  There is faint rattling coming from the northeast.
  0   0  
   \ /   
 0--@
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "You hear faint rattling.");
   set_items( ([
                "light":
       "There is faint light to the northwest.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac030",
                "northwest": PATH+"catac021",
                "west": PATH+"catac026",
                ]) );
}
 
void reset() {
   if(!present("skeleton"))
      new(MON_PATH+"skeleton")->move(this_object());
}
