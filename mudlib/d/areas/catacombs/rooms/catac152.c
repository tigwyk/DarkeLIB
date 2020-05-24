/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
int num_sits = 0;
 
void init() {
   ::init();
   add_action("sit_down", "sit");
}
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The walls of this large room are rounded, forming a big circle.  The 
   floor is littered with small pebbles, and against the northeastern 
   wall is a rock that is about two feet tall.
      0  
     /   
 0--@
     \
      0  
ext);
   set_smell("default", "The air smells fresh.");
   set_listen("default", "You hear something scurrying nearby.");
   set_items( ([
                "pebbles":
        "Small pebbles litter the floor.",
                "rock":
        "The rock looks like it may provide a nice place to sit and rest.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "west": PATH+"catac118",
                "northeast": PATH+"catac104",
                "southeast": PATH+"catac120",
                ]) );
}
 
int sit_down(string str) {
   int temp;
 
   if(!str)
      return 0;
 
   if(str != "rock" && str != "on rock") {
      notify_fail("Sit on what?\n");
      return 0;
   }
   message("info", "You sit on the rock and rest for a moment.",
           this_player());
   message("info", this_player()->query_cap_name()+
           " sits on a rock and rests for a moment.", this_object(),
           this_player());
   if(num_sits < 3) {
      if(random(5) != 0)
         return 1;
      temp = 10+random(10);
      this_player()->add_hp(temp);
      num_sits++;
      if(random(5) == 0)
         this_player()->add_poisoning(-10000);
   }
   return 1;
} 
 
void reset() {
   ::reset();
   num_sits = 0;
}
