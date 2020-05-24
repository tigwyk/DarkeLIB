/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The ceiling and walls are close to your body, and you are forced to 
   walk carefully in order to avoid hitting your head on the ceiling and 
   to avoid banging into the rock walls.  The passageway opens up a bit 
   to the north, while it continues to narrow slightly as it heads 
   southeast.
    0   
    |   
    @
     \
      0  
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear cackling nearby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "north": PATH+"catac129",
                "southeast": PATH+"catac131",
                ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("skeleton")) {
      ob = new(MON_PATH+"skeleton");
      ob->move(this_object());
      ob->set("aggressive", 1);
   }
}
 
