/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This corridor runs into the western part of the catacombs, taking 
   you further and further away from the entrance to this level.  To 
   the east lies an intersection of passageways while to the west 
   the passageway forks, with one corridor running southwest.  As 
   you gaze about the room, you have the strangest feeling that you 
   are not alone.
  
 0--@--0
   /
  0    
ext);
   set_smell("default", "The air smells of death.");
   set_listen("default", "You hear a low whimper.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "east": PATH+"catac118",
                "west": PATH+"catac144",
                "southwest": PATH+"catac134",
                ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("gold skeleton")) {
      ob = new(MON_PATH+"goldskel");
      ob->move(this_object());
   }
}
 
