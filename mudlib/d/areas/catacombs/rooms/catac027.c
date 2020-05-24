/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   Relying on your sense of direction, you arrive at the conclusion that 
   this chamber must be the southernmost of this level.  The most striking 
   feature of the area is a small stone staircase that winds down, to the 
   next deepest level of the catacombs.  As you gaze down the stairs, all 
   that you are able to see is darkness.
    0   
    |   
    @    down 
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                ({"stairs", "staircase"}):
         "The staircase winds downward into the darkness below.",
                         ]) );
   set_exits( ([
                "north": PATH+"catac025",
                "down": PATH+"catac100",
                ]) );
}
