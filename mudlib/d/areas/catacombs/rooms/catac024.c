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
   yourself on the stalactites.  There is faint light to the northeast.  
   You hear the clanging of metal to the southeast.
      0  
     /   
    @
     \
      0  
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                ({"stalactite", "stalactites"}):
     "The stalactites are very long and hang almost to the floor in places.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac023",
                "southeast": PATH+"catac025",
                ]) );
}
 
void reset() {
   if(!present("skeleton"))
      new(MON_PATH+"skeleton")->move(this_object());
}
