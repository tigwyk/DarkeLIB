/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "This is a trail that winds through the kobold campgrounds.  Everywhere "
   "kobolds of all shapes and sizes are running from place to place, always "
   "busy doing something.  You hear children laughing and kobold soldiers "
   "barking orders at each other.  You see more tents to the east and "
   "several kobold soldiers in that direction.  The trail continues to "
   "the northeast and to the south from here."
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  There seem to be more tents to the east and "
   "several dark figures standing around them.  The trail continues to "
   "the northeast and to the south from here."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear soldiers talking nearby.");
   set_items( ([
                "tents": "There are quite a few tents to the east.",
                "figures": "They seem to be kobold soldiers.",
                ]) );
   set_exits( ([
                "northeast": PATH+"trail08",
                "east": PATH+"camp36",
                "south": PATH+"trail06",
                ]) );
}
