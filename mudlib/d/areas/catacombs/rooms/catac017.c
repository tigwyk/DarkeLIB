/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   The passageway opens into a small chamber littered with small stones.  
   Bones lie on the ground, presumably from a recent monster's kill, as 
   most of them are pink with blood.  The bones on the floor roll over 
   occasionally, for no apparent reason, producing a rattling sound.     
       
    @
   /
  0    
ext);
   set_smell("default", "You smell the blood of unlucky adventurers.");
   set_listen("default", "You hear the rattling of bones.");
   set_items( ([
                "bones":
     "The blood-stained bones rattle slightly, sending a chill up your spine.",
                ({"stones", "pebbles"}):
     "Little pebbles are strewn about on the ground.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac011",
                ]) );
   new(MISC_PATH+"fountain")->move(this_object());
}
 
void reset() {
   ::reset();
   if(!present("silvskel"))
      new(MON_PATH+"skeleton")->move(this_object());
}
 
void init() {
   ::init();
 
   add_action("do_drink", "drink");
}
 
int do_drink(string str) {
   if(!str) {
      notify_fail("What do you want to drink?\n");
      return 0;
   }
   if(str != "water" && str != "fountain") {
      return 0;
   }
   this_player()->add_quenched(5);
   write("You bend down and drink the clear water from the fountain.\n");
   say(this_player()->query_cap_name()+" gulps water from the fountain.\n",
         this_player());
   return 1;
}
 
