/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "The large planting fields provide the kobold community with much of "
   "its food.  Farmers are busy tilling the soil and watering the crops, "
   "in order to produce enough food to fill the many hungry mouths.  To "
   "the south you see the tents of the kobold families."
   );
   set("night long",
   "Even at night farmers are here in the fields working the crops.  With "
   "so many mouths to feed, farmers are required to work at all hours of "
   "the day in order to fill hungry mouths.  Although it is difficult to "
   "see in the faint moonlight, farmers work hard to feed their fellow "
   "kobolds."
   );
   set_smell("default", "The scent of fresh potatoes fills your nostrils.");
   set_listen("default", "You hear hard-working farmers huffing and puffing.");
   set_items( ([
                "farmers":
      "Several farmers are hard at work.  They look tired.",
                ({"farm", "fields", "planting fields"}):
      "The planting fields are very dry.  It is a wonder than anything grows here.",
                ]) );
   set_exits( ([
                "west": PATH+"camp35",
                "east": PATH+"camp21",
                ]) );
}
 
void reset() {
   if(!present("kobold farmer"))
      new(MON_PATH+"farmer")->move(this_object());
      new(MON_PATH+"farmer")->move(this_object());
      new(MON_PATH+"farmer")->move(this_object());
}
