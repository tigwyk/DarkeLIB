/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "This small trail heads northwest away from the kobold campgrounds.  In "
   "the distance to the northeast you spy some large tents, while the "
   "planting fields and family tents lie somewhere to the southwest.  You "
   "spy a sign in the middle of the road a little ways to the north."
   );
   set("night long",
   "You squint your eyes in an attempt to make out the scene before you.  "
   "This path leads you away from the kobold campgrounds and into the plains "
   "to the northwest.  To the northeast you can barely make out the large "
   "tents of the kobold chieftain, while the planting fields and family tents "
   "in the southwest are scarcely visible in the moonlight."
   );
   set_listen("default", "You heard a bird chirping.");
   set_items( ([
                "tents":
"There are large tents to the northeast and smaller ones to the southwest.",
                "sign":
       "You are much too far away from the sign to read it.",
                ]) );
   set_exits( ([
                "northwest": PATH+"trail10",
                "southeast": PATH+"trail08",
                ]) );
}
