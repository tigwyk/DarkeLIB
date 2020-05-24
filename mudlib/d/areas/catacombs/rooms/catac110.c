/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   Three passageways converge here in a three-way intersection.  To 
   the northeast, a narrow, low-ceilinged corridor runs off into 
   darkness, while the passageways to the west and south seem to 
   head towards better-lit areas.
      0  
     /   
 0--@
    |
    0   
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac151",
                "south": PATH+"catac109",
                "northeast":PATH+"catac140",
                ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("giant skeleton")) {
      ob = new(MON_PATH+"giant_skeleton");
      ob->move(this_object());
      ob->set("aggressive", 0);
   }
}
 
