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
   "barking orders at each other.  Several large tents lie to the northeast, "
   "while many smaller ones lie to the southeast."
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  Several large tents are visible to the northeast, "
   "while there are many smaller ones to the southeast."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear soldiers talking nearby.");
   set_items( ([
                "tents":
"There are large tents to the northeast and smaller ones to the southeast.",
                ]) );
   set_exits( ([
                "northeast": PATH+"camp23",
                "northwest": PATH+"trail09",
                "southeast": PATH+"camp37",
                "southwest": PATH+"trail07",
                ]) );
}
