/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   You stand at the southernmost part of a large, domed room.  Like the 
   chambers in the previous level, the floor, walls, and ceiling are 
   comprised of stone blocks.  It is very cold, so cold that you wonder 
   if it is a natural chill.  Once in a while you hear a demonic laugh 
   coming from far to the north.  Small torches provide a little light.
    0   
    |   up   
    @  
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the north.");
   set_items( ([
                "ceiling":
        "The ceiling is over 30 feet high.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "up": PATH+"catac149",
                "north": PATH+"catac201",
                ]) );
}
