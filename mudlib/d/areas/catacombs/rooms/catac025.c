/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   The ceiling dips steeply here, and you are forced to lower your head 
   for fear fear of injuring yourself on any stalactites.  Bones are 
   scattered about the room, and a few rusty weapons lie in one 
   corner.  The corridor branches to the northwest and northeast, 
   while a dark corridor leads to the south.
  0   0  
   \ /   
    @
    |
    0   
ext);
   set_smell("default", "The air smells fresh.");
   set_listen("default", "Your footsteps echo loudly in the chamber.");
   set_items( ([
                ({"bone", "bones"}):
"There are a few bones here, most of which seem to have teeth marks on them.",
                ({"weapons", "rusty weapons", "rusted weapons"}):
       "Several rusted weapons lie in a pile in one corner.",
                ({"ceiling", "stalactites"}):
"The stalactites would cause serious damage should you hit your head on them.",
                ]) );
   set_exits( ([
                "south": PATH+"catac027",
                "northwest": PATH+"catac024",
                "northeast": PATH+"catac026",
                ]) );
   set_pre_exit_functions( ({"south"}), ({"go_south"}) );
}
 
int go_south() {
   if(present("skeleton warrior")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The skeleton warrior claws you in the face and pushes you back!");
      this_player()->add_hp(-5);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go south, but was struck in the face by the "+
        "skeleton warrior and was pushed back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
void reset() {
   ::reset();
 
   if(!present("skeleton warrior")) {
      new(MON_PATH+"skelwarr")->move(this_object());
   }
}
