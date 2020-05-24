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
   "barking orders at each other.  The family tents lie to the west and you "
   "see farms to the northwest.  You hear animal noises coming from the "
   "east.  The trail continues to the north."
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  The trial continues to the north."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear animals making noises nearby.");
   set_items( ([
                ({"farm", "farms"}):
         "You see farms and planting fields to the northwest.",
                ]) );
   set_exits( ([
                "southwest": PATH+"camp11",
                "north": PATH+"trail05",
                "east": PATH+"camp15",
                ]) );
}
