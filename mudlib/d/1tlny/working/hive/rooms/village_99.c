//      Wizard:  Myrddin
//      village_99.c
//      June 97

#include "/wizards/myrddin/defs/defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("insectoid_g02")) {
         new(HIV_MON+"insectoid_g02")->move(this_object());
         new(HIV_MON+"insectoid_g02")->move(this_object());
         new(HIV_MON+"insectoid_g02")->move(this_object());
  }  
if(!present("insectoid_eg01")) {
         new(HIV_MON+"insectoid_eg01")->move(this_object());
         new(HIV_MON+"insectoid_eg01")->move(this_object());
  }
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Upper Hill");
    set("long",
	"You are high enough on the hill to see the nearby terrain "
              "over the surrounding forest.  The hill retains its cover of "
              "rocks and underbrush, but has one other notable feature.  "
              "There is a deep depression of freshly turned earth, "
              "approximately 5 feet wide.  The insectoids seem to be "
              "watching the depression very carefully, as if it were a "
              "threat.\n" );
    set("night long",
             "In the dark, one part of the hill looks much like another.  "
             "Shadows broken by jutting rocks, blending with thick "
             "brush, and the rustle of nearby insectoids.  You must, "
             "however, be higher up on the hill since you can see a glow "
             "over the forest, marking the position of the village.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear subtle scratchings and quiet "
              "movement coming from all over the hill.  The sounds of "
              "normal wildlife are noticeably absent.");
    set_items(([
     ({ "forest" }) :
        "At this height, you can look out over the forest.  It waves in the "
        "wind like a sea of green.  In the distance, you can make out the "
        "position of the village, easily marked by the smoke rising "
        "above it.",
     ({ "village" }) :
        "You can't see it clearly at this distance, it is all you can do to "
        "locate its position.",
     ({ "depression" }) :
        "It is a bowl shaped depression, with a fair amount of dirt "
        "stacked around the hole.  With the way they are watching the "
        "depression so carefully, you get the distinct impression that the "
        "insectoids tunneled up from there, then refilled it in an effort "
        "to cut off any pursuit. ",
     ({ "glow" }) :
        "It is coming from the villages bonfire.  You can't see it clearly "
        "at all at this distance, and in the dark, but the fire clearly "
        "marks its position.",
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
    set_exits((["southeast":HIV_ROOMS+"village_98.c",
                     "west":HIV_ROOMS+"village_93.c",
                     "east":HIV_ROOMS+"village_92.c",
                     "south":HIV_ROOMS+"village_97.c",
                     "northeast":HIV_ROOMS+"village_90.c",
                     "northwest":HIV_ROOMS+"village_91.c",
                     "southwest":HIV_ROOMS+"village_96.c",
                     "north":HIV_ROOMS+"village_95.c"])); 
}
