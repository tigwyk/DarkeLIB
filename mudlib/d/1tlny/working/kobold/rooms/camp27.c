/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing in the northeastern part of a circle of small tents.  "
   "In the center of the circle is a larger tent, perhaps the home of "
   "the leader of these kobolds.  Heavily-armed guards and soldiers "
   "patrol the area, wary of anyone who approaches.  There is a large "
   "pile of rubble here that prevents movement in any direction other "
   "than to the west."
   );
   set("night long",
   "In the pale moonlight you are able to make out a circle of small tents "
   "that surround a larger tent, perhaps the home of the leader of these "
   "kobolds.  Guards patrol the area and watch for night intruders.  "
   "Small fires light up the area a bit.  There is a large pile of rubble "
   "here that prevents movement in any direction other than to the west."
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
                "west": PATH+"camp26",
                ]) );
}
 
void reset() {
   object ob1, ob2;
   ::reset();
   if(!present("kobold fighter")) {
      ob1 = new(MON_PATH+"fighter");
      ob1->set("aggressive", 1);
      ob1->move(this_object());
   }
   if(!present("kobold shaman")) {
      ob2 = new(MON_PATH+"shaman");
      ob2->set("aggressive", 1);
      ob2->move(this_object());
   }
}
 
