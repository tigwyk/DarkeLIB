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
   "barking orders at each other.  There are few tents along this part of "
   "the trail and you hear gruff voices nearby.  The trail runs north and "
   "southwest from here."
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  You hear gruff voices nearby.  The trail runs "
   "north and southwest from here."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear soldiers talking nearby.");
   set_items( ([
 
                ]) );
   set_exits( ([
                "southwest": PATH+"trail05",
                "north": PATH+"trail07",
                ]) );
}
 
void reset() {
   if(!present("kobold hunter"))
      new(MON_PATH+"hunter")->move(this_object());
}
 
