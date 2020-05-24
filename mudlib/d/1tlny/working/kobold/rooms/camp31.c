/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing inside the fences that house the few chickens owned "
   "by the kobold community.  There is seed scattered about on the ground."
   "  There are other animal pens to the west and southwest.",
   );
   set("night long",
   "You are standing inside the fences that house the few chickens owned "
   "by the kobold community.  There is seed scattered about on the ground."
   "  There are other animal pens to the west and southwest.",
   );
   set_smell("default", "The scent of animal waste pervades your nostrils.");
   set_listen("default", "You hear animal noises.");
   set_items( ([
                "seed":
        "There is seed all over the ground.",
                ({"fence", "fences"}):
        "These fences keep the chickens from running away.",
                ]) );
   set_exits( ([
                "west": PATH+"camp15",
                "southwest": PATH+"camp16",
                ]) );
}
 
void reset() {
   if(!present("chicken")) {
      new(MON_PATH+"chicken")->move(this_object());
      new(MON_PATH+"chicken")->move(this_object());
      new(MON_PATH+"chicken")->move(this_object());
   }
}
