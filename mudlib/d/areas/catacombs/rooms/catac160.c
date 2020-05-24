/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void init() {
   ::init();
   add_action("enter", "enter");
}
 
void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This secret room seems to be the abode of some undead creature.  
   A tall mirror lies in the northern part of the room, while torches 
   affixed to the wall provide ample light.  The only exit seems 
   to be up.
       
        up   
    @ 
ext);
   set_smell("default", "The air smells of rotting flesh.");
   set_listen("default", "You hear the shuffling of feet closeby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                "mirror":
        "The mirror is in fine condition.",
               ]) );
   set_exits( ([
                "up": PATH+"catac112",
                ]) );
   set_pre_exit_functions( ({"up"}), ({"go_up"}) );
}
 
void reset() {
   object ob;
 
   ::reset();
   if(!present("giant mummy")) {
      ob = new(MON_PATH+"giant_mummy");
      ob->set_moving(0);
      ob->move(this_object());
      ob->add_spell("rot", "");
      ob->set_spell_level("rot", 5);
      ob->force_me("cast *5 rot");
   }
}
 
int go_up() {
   if(present("giant mummy")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The giant mummy claws you in the face and pulls you back!");
      this_player()->add_hp(-5);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go up, but was struck in the face by the "+
        "giant mummy and was pulled back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
int enter(string str) {
   if(!str) 
      return 0;
   if(str != "mirror" && str != "portal") {
      notify_fail("Enter what?\n");
      return 0;
   }
   write("You enter the mirror and are transported somewhere!");
   this_player()->move_player(find_object_or_load(PATH+"catac211"));
   message("info", this_player()->query_cap_name()+
      " enters the mirror and disappears!", this_object(), this_player());
   return 1;
}
