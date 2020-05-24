/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 1);
   set("short", "Kobold Campgrounds");
   set("long",
"This appears to be the western half of a rather large tent, that largest "
"in the whole campground.  Guards eye you suspiciously and adjust their "
"positions nervously, keeping a watchful eye over the person they are "
"guarding: the kobold chieftain.  Torches provide a lot of light, "
"and they illuminate the chieftain's large, wooden throne.  The entrance "
"of the tent lies to the east."
);
   set_listen("default", "You hear guards barking orders at each other outside.");
   set_items( ([
                ({ "tent", "large tent" }):
       "It is the largest tent in the whole campground.  The kobold chieftain probably lives here.",
                "throne":
       "The wooden throne stands nearly ten feet high.",
                "guards":
       "The kobold guards seem to be quite fierce.",
                "torches":
       "The torches brighen up the area.",
                ]) );
   set_exits( ([
                "east": PATH+"camp29",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("kobold guard")) {
      new(MON_PATH+"guard")->move(this_object());
      new(MON_PATH+"guard")->move(this_object());
      new(MON_PATH+"guard")->move(this_object());
   }
   if(!present("kobold chieftain"))
      new(MON_PATH+"chief")->move(this_object());
}
 
