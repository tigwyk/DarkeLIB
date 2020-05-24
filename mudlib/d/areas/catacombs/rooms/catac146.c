/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This secret room is set apart from the rest of the dungeon for some 
   reason.  Bones are scattered about the room, and a few rusty weapons 
   lie in one corner.  You spy a staircase leading down in the room to 
   the east.
 
    @--0
   /
  0    
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"bone", "bones"}):
"There are many bones here, most of which seem to have teeth marks on them.",
                ({"weapons", "rusty weapons", "rusted weapons"}):
       "Several rusted swords and daggers lie in a pile in one corner.",
                ({"stairs", "staircase"}):
       "The stairs are located in the room to the east.",
                 ]) );
   set_exits( ([
                "east": PATH+"catac149",
                "southwest": PATH+"catac140",
                ]) );
   set_pre_exit_functions( ({"east"}), ({"go_east"}) );
}
 
void reset() {
   ::reset();
   if(!present("skeleton warrior")) {
      new(MON_PATH+"skelwarr")->move(this_object());
      new(MON_PATH+"skelwarr")->move(this_object());
   }
}
 
int go_east() {
   if(present("skeleton warrior")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 60) return 1;
      if(this_player()->query_stealth() >= 85) return 1;
      write("The skeleton warrior claws you in the face and pushes you back!");
      this_player()->add_hp(-5);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go east, but was struck in the face by the "+
        "skeleton warrior and was pushed back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
