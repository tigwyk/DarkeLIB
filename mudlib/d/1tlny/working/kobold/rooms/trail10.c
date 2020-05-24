/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are walking on a small dirt path that leads through the plains of "
   "DarkeMud.  To the south lies what seems to be a small village of some "
   "kind, while to the north the path continues.  To the north you also "
   "spy a sign standing in the middle of the road, but you are too far away "
   "to read the writing on the wooden plank.  The plains surround you on "
   "either side of the path."
   );
   set("night long",
   "It is quite difficult to see anything on this dark night.  You seem to "
   "be walking on a dirt path that winds through the plains of DarkeMud.  "
   "There is faint light to the south, while only darkness lies to the "
   "north, east, and west."
   );
   set_listen("default", "You heard a bird chirping.");
   set_items( ([
                "plains":
       "The grasses of the plains shiver slightly in the wind.",
                "village":
       "There appears to be some kind of village to the south.",
                "sign":
       "You are too far away from the sign to read it.",
                ]) );
   set_exits( ([
                "north": PATH+"trail11",
                "southeast": PATH+"trail09",
                ]) );
}
 
 
