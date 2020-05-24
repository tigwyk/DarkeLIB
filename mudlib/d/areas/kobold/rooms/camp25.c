/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing in the western part of a circle of small tents.  "
   "In the center of the circle is a larger tent, perhaps the home of "
   "the leader of these kobolds.  Heavily-armed guards and soldiers "
   "patrol the area, wary of anyone who approaches.  You see several "
   "particularly strong-looking kobolds to the northeast."
   );
   set("night long",
   "In the pale moonlight you are able to make out a circle of small tents "
   "that surround a larger tent, perhaps the home of the leader of these "
   "kobolds.  Guards patrol the area and watch for night intruders.  "
   "Small fires light up the area a bit.  You see several particularly "
   "strong-looking kobolds to the northeast."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear guards barking orders at each other.");
   set_items( ([
                "tent":
       "The smaller tents or the large tent?",
                ({"small tents", "smaller tents", "tents"}):
       "Kobold fighters and guards probably live in those tents.",
                "large tent":
       "It is the largest tent in the whole campground.  The kobold chieftain probably lives there.",
                ]) );
   set_exits( ([
                "northeast": PATH+"camp26",
                "southeast": PATH+"camp23",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("kobold guard"))
      new(MON_PATH+"guard")->move(this_object());
}
 
