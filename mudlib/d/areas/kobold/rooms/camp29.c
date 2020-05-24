/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 1);
   set("short", "Kobold Campgrounds");
   set("long",
"This appears to be the eastern half of a rather large tent, the largest "
"in the whole campground.  Guards eye you suspiciously and adjust their "
"positions nervously.  Torches provide a lot of light, although aside from "
"the guards, there is little to see.  To the west lies a large throne of "
"some kind, on which sits a massive kobold.  He is surrounded by several "
"tough-looking guards."
);
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear guards barking orders at each other outside.");
   set_items( ([
                ({ "tent", "large tent" }):
       "It is the largest tent in the whole campground.  The kobold chieftain probably lives here.",
                ({"chieftain", "kobold chieftain" }):
       "To the west, the kobold chieftain sits on his throne.",
                "guards":
       "The kobold guards seem to be quite fierce.",
                "torches":
       "The torches brighen up the area.",
                ]) );
   set_exits( ([
                "west": PATH+"camp30",
                "east": PATH+"camp28",
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
 
