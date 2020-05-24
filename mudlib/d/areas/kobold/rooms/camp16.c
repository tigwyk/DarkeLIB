/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "This pen holds several sheep and is overseen by the sole shepherd of "
   "the kobold community.  There are piles of freshly-cut grass for the "
   "sheep to eat, although the sheep seem more interested in eating your "
   "clothing!  There are other animal pens in this area in several "
   "directions."
   );
   set("night long",
   "This pen holds several sheep and is overseen by the sole shepherd of "
   "the kobold community.  There are piles of freshly-cut grass for the "
   "sheep to eat, although the sheep seem more interested in eating your "
   "clothing!"
   );
   set_smell("default", "The scent of animal waste pervades your nostrils.");
   set_listen("default", "You hear animal noises.");
   set_items( ([
                ({"grass", "piles", "piles of grass"}):
        "The sheep like to munch on the fresh green grass.",
                ]) );
   set_exits( ([
                "west": PATH+"camp17",
                "north": PATH+"camp15",
                "northeast": PATH+"camp31",
                ]) );
}
 
void reset() {
   if(!present("fluffy sheep")) {
      new(MON_PATH+"sheep")->move(this_object());
      new(MON_PATH+"sheep")->move(this_object());
   }
   if(!present("kobold shepherd"))
      new(MON_PATH+"shepherd")->move(this_object());
}
