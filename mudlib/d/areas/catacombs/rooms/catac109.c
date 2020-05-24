/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
int found = 0;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This medium-sized chamber is strewn with rather large rocks from one end 
   of the room to the other.  Most of the rocks are smaller than your head, 
   but some of them would stand taller than most kobolds.  Passageways 
   leave this room to the southwest, north, and southeast.
    0   
    |   
    @
   / \
  0   0  
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_search("rocks", (: call_other, this_object(), "search_rocks" :) );
   set_items( ([
                ({"rocks"}):
        "The rocks would provide a good place for hiding something, you think.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "north": PATH+"catac110",
                "southwest": PATH+"catac103",
                "southeast": PATH+"catac108",
                ]) );
}
 
 
int search_rocks(string str) {
   if(!str) return 0;
   if(str != "rocks") {
      notify_fail("Search what?\n");
      return 0;
   }
   if(this_player()->query_skill("perception") >= 20+random(50) && found < 3) {
      message("info", "You search the rocks and find a torch hidden among them.",
         this_player());
      message("info", this_player()->query_cap_name() +
         " searches the rocks and finds a torch hidden among them.",
          this_object(), this_player());
      new("/std/obj/torch")->move(this_object());
      found++;
   }
   else {
      message("info", "You search between the rocks but find nothing.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches the rocks.",
            this_object(), this_player() );
   }
   return 1;
}
 
void reset() {
   ::reset();
   if(!present("bronze skeleton"))
      new(MON_PATH+"brnzskel")->move(this_object());
}
