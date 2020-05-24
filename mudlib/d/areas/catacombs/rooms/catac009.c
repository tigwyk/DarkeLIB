/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "A Large Chamber in Some Catacombs");
   set("long",@ext
   This is the western side of a large chamber of the catacombs.  There 
   is a large puddle of water here, which seems to be fed by a small 
   trickle of water that leaves the wall.  The wall is cracked in places 
   here, as if an earthquake had caused the damage.  There is one 
   especially large crack that runs from the floor to the ceiling.
      0  
     /   
    @--0    
ext);
   set_smell("default", "The air has a clean, fresh smell.");
   set_listen("default", "You hear the trickling of water.");
   set_search("default",
      "It seems that you could easily pass through the crack in the "
      "northwestern part of the wall.");
   set_search("crack",
      "It seems that you could easily pass through the crack in the "
      "northwestern part of the wall.");
   set_items( ([
                ({"crack", "large crack"}):
        "The crack is on the northwestern wall.  It seems as though someone "+
        "might be able to fit through it.",
                "cracks":
        "Cracks riddle the wall on this side of the catacomb chamber.",
                ({"water", "puddle"}):
        "There is a small pool of water that is very cool to the touch.",
                ]) );
   set_exits( ([
                "east": PATH+"catac008",
                "northwest": PATH+"catac016",
                "northeast": PATH+"catac010",
               ]) );
   set_invis_exits( ({"northwest"}) );
}
