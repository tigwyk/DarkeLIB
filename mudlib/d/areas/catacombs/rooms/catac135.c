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
   The corridor breaks into two smaller passages, one to the northeast, 
   the other to the east.  You can hear faint sniffling to the west 
   somewhere, but there is otherwise not a sound in the catacombs.  A 
   number of small stones lie scattered about on the floor.
  0   0  
   \ /   
    @--0    
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear sniffling in the distance.");
   set_search("stones", (: call_other, this_object(), "search_stones" :) );
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac136",
                "northeast": PATH+"catac144",
                "east": PATH+"catac134",
                ]) );
}
 
int search_stones(string str) {
   object ob;
 
   if(!str) return 0;
   if(str != "stones") {
      notify_fail("Search what?\n");
      return 0;
   }
   if(this_player()->query_skill("perception") >= 50+random(50) && found == 0) {
      message("info", "You search the stones and find a bone dagger hidden among them.",
         this_player());
      message("info", this_player()->query_cap_name() +
     " searches around the stones and finds a bone dagger hidden among them.",
          this_object(), this_player());
      ob = new(WEAP_PATH+"bonedggr");
      ob->set_auto_critical("cold B");
      ob->add_poisoning(50);
      ob->set_quality(6);
      ob->move(this_object());
      found = 1;
   }
   else {
      message("info", "You search between the stones but find nothing.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches the stones.",
            this_object(), this_player() );
   }
   return 1;
}
 
 
