/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway heads northeast for a short distance before coming 
   to a sudden end.  The rock walls are just a few feet apart, 
   the passageway coming to an end at a rounded wall.  The corridor 
   runs back to the southwest, where the rest of the catacombs lie.  
   A couple torches affixed to the wall provide a little light.
   
    @
   /
  0    
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear grunting to the northeast.");
   set_search("default", "You discover that the northeastern wall is an illusion!");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac110",
                "northeast": PATH+"catac146",
                ]) );
   set_invis_exits( ({"northeast"}) );
   set_pre_exit_functions( ({"northeast"}), ({"go_northeast"}) );
}
 
int go_northeast() {
   if(present("bronze skeleton")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The bronze skeleton beats you in the head with its fist!");
      this_player()->add_hp(-10);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go northeast, but was struck in the head by the "+
        "bronze skeleton and was pushed back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
void reset() {
   ::reset();
   if(!present("bronze skeleton"))
      new(MON_PATH+"brnzskel")->move(this_object());
}
 
int no_exit() { return 1; }
 
void init() {
   ::init();
 
   if(this_player()->chk_my_mob())
      add_action("no_exit", "northeast");
}
