//      Wizard:  Myrddin
//      village_76.c
//      June 97

#include "/wizards/myrddin/defs/defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("insectoid_g01")) {
         new(HIV_MON+"insectoid_g01")->move(this_object());
   }  
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Lower Hill");
    set("long",
	"You stand on the west side of the hill.  From here you "
              "could probably make your way to the back of the hill.  "
              "Even the back of the hill is probably well defended, but it "
              "wouldnt hurt to scout it out.\n" );
    set("night long",
             "In the dark, one part of the hill looks much like another.  "
             "Shadows broken by jutting rocks, blending with thick "
             "brush, and the rustle of nearby insectoids.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear subtle scratchings and quiet "
              "movement coming from all over the hill.  The sounds of "
              "normal wildlife are noticeably absent.");
    set_items(([
     ({ "trees" }) :
        "Their are still trees desperately trying to grow on the hill.  "
        "They look small and scrawny compared to their brethren on "
        "the fertile soil below the hill.",
    ({ "rock", "rocks" }) :
        "They are all over the hill, and come in various sizes.  Some "
        "seem small enough to throw, others could easily be used as "
        "material for building a castle.",
     ({ "hill" }) :
        "The hill rises above the rest of the forest like an island in an "
        "ocean.  It would be interesting to learn how this hill came to be "
        "when there are no others in the area.  It certainly would make "
        "an ideal defensive point for the entire region.",
     ({ "groundcover", "undergrowth"  }) :
        "There is still a lot of brush growing on the hill, as it is better "
        "able to adapt to the thin soil of the hillside.  It, with the "
        "pervasive rocks, tends to block your view of the surrounding "
        "terrain.",
]));
    set_exits((["northeast":HIV_ROOMS+"village_77.c",
                     "southeast":HIV_ROOMS+"village_88.c",
                     "south":HIV_ROOMS+"village_75.c"])); 
}

