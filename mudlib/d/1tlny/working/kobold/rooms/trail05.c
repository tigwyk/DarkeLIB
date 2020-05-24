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
   "barking orders at each other.  To the northwest lies planting fields, "
   "while you hear animal noises coming from the southeast.  The trial "
   "continues to the northeast and to the south."
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  You manage to make out farms to the northwest.  "
   "The trail continues to the northeast and to the south."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear children laughing nearby.");
   set_items( ([
                ({"farms", "fields", "planting fields", "farm"}):
         "The farms are just a few steps to the northwest.",
                ]) );
   set_exits( ([
                "northwest": PATH+"camp18",
                "northeast": PATH+"trail06",
                "south": PATH+"trail04",
                ]) );
}
 
void reset() {
   if(!present("kobold hunter"))
      new(MON_PATH+"hunter")->move(this_object());
}
 
