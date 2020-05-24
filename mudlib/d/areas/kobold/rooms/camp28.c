/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing in the eastern part of a circle of small tents.  "
   "In the center of the circle is a larger tent, perhaps the home of "
   "the leader of these kobolds.  Heavily-armed guards and soldiers "
   "patrol the area, wary of anyone who approaches.  The largest "
   "tent in the area lies to the west."
   );
   set("night long",
   "In the pale moonlight you are able to make out a circle of small tents "
   "that surround a larger tent, perhaps the home of the leader of these "
   "kobolds.  Guards patrol the area and watch for night intruders.  "
   "Small fires light up the area a bit.  The larges tent in the area "
   "lies to the west and is well-lit by the fires surrounding it."
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
                "west": PATH+"camp29",
                "southwest": PATH+"camp24",
                ]) );
   set_pre_exit_functions( ({"west"}), ({"go_west"}) );
}
 
void reset() {
   ::reset();
   if(!present("kobold guard")) {
      new(MON_PATH+"guard")->move(this_object());
      new(MON_PATH+"guard")->move(this_object());
   }
}
 
int go_west() {
   if(present("kobold guard")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 30) return 1;
      if(this_player()->query_stealth() >= 40) return 1;
      write("The kobold guard pushes you back and shakes his head.");
      tell_room(this_object(), this_player()->query_cap_name() +
            " tried to go west, but was pushed back by the kobold guard.",
          ({ this_player() }) );
      return 0;
      }
   else
      return 1;
}
 
