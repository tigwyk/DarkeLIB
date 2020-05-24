 
#include "std.h"
inherit ROOM;
 
int searched = 0;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The hallway is clogged here by a massive pile of foul-smelling rags. 
   The tattered and filthy clothing covers the floor, making it somewhat 
   difficult to stand up straight.  The passageway continues to the 
   northwest, southwest, and east.
  0    
   \   
    @--0
   /
  0    
ext);
   set_smell("default", "You smell something most foul.");
   set_listen("default", "You hear moaning very nearby.");
   set_search("rags", (: call_other, this_object(), "search_rags" :) );
   set_items( ([
                ({"pile", "rags", "pile of rags", "clothing"}):
        "The mound of rags seems to shift slightly as you gaze at it.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac112",
                "east": PATH+"catac110",
                "southwest": PATH+"catac101",
                ]) );
}
 
int search_rags(string str) {
   object ob, ob2;
 
   if(!str) return 0;
   if(str != "rags" && str != "pile of rags") {
      notify_fail("Search what?\n");
      return 0;
   }
   if(searched != 0) {
      message("info", "You search the pile of rags but find nothing.",
              this_player());
      message("info", this_player()->query_cap_name()+ " searches the "+
              "pile of rags but finds nothing.", this_object(), this_player());
   }
   else {
      searched = 1;
      message("info", "You search the pile of rags, disturbing a shaggy "+
              "zombie that was hiding in the rags!", this_player());
      message("info", this_player()->query_cap_name()+" searches the pile "+
              "of rags and disturbs a shaggy zombie that was hiding "+
              "there!", this_object(), this_player());
      ob = new(MON_PATH+"shagzomb");
      ob->move(this_object());
      ob->set_skill("thrown", 85);
      ob2 = new(WEAP_PATH+"bonedggr");
      ob2->move(ob);
      ob->force_me("throw dagger at "+this_player()->query_name());
   }
   return 1;
}
