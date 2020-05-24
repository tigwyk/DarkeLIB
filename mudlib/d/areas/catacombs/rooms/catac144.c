/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The dark passageway takes a gentle turn here, heading to the 
   southwest for a bit.  A rusty, broken helmet lies on one side 
   of the corridor, while a torn and battered pair of leather boots 
   lie on the other side.
   
    @--0
   /
  0    
ext);
   set_smell("default", "The air smells stale.");
   set_listen("default", "You hear whimpering nearby.");
   set_items( ([
                ({"boots", "leather boots"}):
        "These boots are probably the lost possessions on some hapless adventurer.",
                ({"helmet", "broken helmet", "rusty helmet"}):
        "This helmet most likely belonged to an adventurer at some forgotten time.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "east": PATH+"catac133",
                "southwest": PATH+"catac135",
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
