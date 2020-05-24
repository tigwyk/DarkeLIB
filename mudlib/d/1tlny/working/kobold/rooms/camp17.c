/* Room coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are standing ankle-deep in foul-smelling mud.  This is obviously "
   "the pig pen that holds the few hairy hogs of the kobold families.  "
   "There are other animal pens to the northeast and east."
   );
   set("night long",
   "You are standing ankle-deep in foul-smelling mud.  This is obviously "
   "the pig pen that holds the few hairy hogs of the kobold families.  "
   "There are other animal pens to the northeast and east."
   );
   set_smell("default", "The scent of animal waste pervades your nostrils.");
   set_listen("default", "You hear animal noises.");
   set_items( ([
                "mud":
        "It's your everyday, run-of-the-mill, plain, ol' MUD!",
                ({"pig pen", "pen"}):
        "This place is as dirty as a pig sty!  ...wait a minute...",
               ]) );
   set_exits( ([
                "northeast": PATH+"camp15",
                "east": PATH+"camp16",
                ]) );
}
 
void reset() {
   if(!present("hairy pig")) {
      new(MON_PATH+"pig")->move(this_object());
      new(MON_PATH+"pig")->move(this_object());
      new(MON_PATH+"pig")->move(this_object());
   }
}
