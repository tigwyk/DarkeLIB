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
   "barking orders at each other.  There seem to be several dozen tents "
   "to the north, each housing a different family.",
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  The campfires keep the families and guards warm.  "
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear children laughing nearby.");
   set_items( ([
                "tents": "The tents are of weak construction.",
                ]) );
   set_exits( ([
                "north": PATH+"camp01",
                "south": PATH+"trail02",
                ]) );
}
 
void reset() {
   if(!present("kobold man"))
      new(MON_PATH+"man")->move(this_object());
}
