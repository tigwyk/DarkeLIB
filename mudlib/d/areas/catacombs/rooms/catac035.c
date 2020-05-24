/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This small secret room is bare save for a large mirror in one corner.  
   As you gaze into the mirror, you are surprised to discover that the 
   mirror bears no reflection.  The glass is pitch black and no image is 
   visible on the shiny surface of the mirror.
   
    @
    |
    0   
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                "mirror":
        "It is strange that the mirror does not reflect light, although you "+
        "are sure that this piece of furniture really is a mirror.",
                "glass":
        "The glass of the mirror is very shiny and highly polished.",
                ]) );
   set_exits( ([
                "south": PATH+"catac033",
                ]) );
}
