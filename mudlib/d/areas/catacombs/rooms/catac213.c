/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This wide corridor runs north from the more narrow passageways and 
   south into a huge chamber.  To the south you spy a large white chair 
   of sorts, as well as a few figures moving about.
    0   
    |   
    @
    |
    0   
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the south.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ({"throne", "chair"}):
        "It appears to be a throne of some kind.",
                "figures":
        "You are unable to tell much about the figures, save that they are humanoids.",
                ]) );
   set_exits( ([
                "north": PATH+"catac212",
                "south": PATH+"catac214",
                ]) );
}
