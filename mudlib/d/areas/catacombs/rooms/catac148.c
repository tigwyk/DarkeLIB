/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This secret room is small and cramped, and also very dark.  A pale 
   figure stands before you, sobbing lightly.  It would seem 
   that this sad fellow must be Rufus Tenderfoot, the 
   adventurer mentioned on the parchment at the entrance to this level
   of the catacombs.  He looks back at you with long, unhappy eyes, from 
   which flow small tears.
      0  
     /   
    @ 
ext);
   set_smell("default", "The air smells of dust.");
   set_listen("default", "You hear someone sobbing.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northeast": PATH+"catac136",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("Rufus Tenderfoot"))
      new(MON_PATH+"rufus")->move(this_object());
}
