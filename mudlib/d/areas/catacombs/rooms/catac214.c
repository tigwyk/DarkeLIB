/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 3);
   set_property("no scry", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This huge room is very brightly lit by several dozen torches affixed 
   to the walls.  The room itself is circular in shape, with only one 
   exit in the northernmost part of the chamber.  In the southern part 
   of the expansive chamber sits a tall throne, made entirely of bone.  
   You sense a great evil that seems to permeate from the walls themselves.
    0   
    |   
    @
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear an occasional laugh.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are bare.",
                ({"torches", "torches"}):
        "The torches that are affixed to the wall provide a lot of light.",
                "throne":
        "The throne is made entirely of bone, and large skull sits atop the piece of furniture.",
                "skull":
        "The large humanoid skull sits atop the bony throne.",
                ]) );
   set_exits( ([
                "north": PATH+"catac213",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("skeleton guard")) {
      new(MON_PATH+"skelgrd")->move(this_object());
      new(MON_PATH+"skelgrd")->move(this_object());
   }
   if(!present("evil lich"))
      new(MON_PATH+"lich")->move(this_object());
}
