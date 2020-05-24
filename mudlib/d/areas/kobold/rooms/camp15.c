/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing in the animal pens that house the few cows owned "
   "by the kobold community.  There is hay strewn about, and you are "
   "forced to step around large piles of cow dung, for fear of smelling "
   "terrible for the rest of the week.  You see the trail to the west, "
   "and other animal pens in several directions."
   );
   set("night long",
   "You are standing in the animal pens that house the few cows owned "
   "by the kobold community.  There is hay strewn about, and you are "
   "forced to step around large piles of cow dung, for fear of smelling "
   "terrible for the rest of the week.  There are other animal pens in "
   "other directions."
   );
   set_smell("default", "The scent of animal waste pervades your nostrils.");
   set_listen("default", "You hear animal noises.");
   set_items( ([
                ({"cow dung", "dung"}):
        "It looks like your average cow dung, complete with buzzing flies.",
                "hay":
        "The hay is brown and dried out.",
                ]) );
   set_exits( ([
                "west": PATH+"trail04",
                "east": PATH+"camp31",
                "southwest": PATH+"camp17",
                "south": PATH+"camp16",
                ]) );
}
 
void reset() {
   if(!present("large cow")) {
      new(MON_PATH+"cow")->move(this_object());
      new(MON_PATH+"cow")->move(this_object());
   }
}
