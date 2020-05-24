/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   The ceiling climbs steeply here, and you are able to raise your head 
   without fear of injuring yourself on any stalactites.  Bones are 
   scattered about the room, and a few rusty weapons lie in one 
   corner.  This place stinks of death.  The corridor branches to the 
   southwest and southeast.
    0   
    |   
    @
   / \
  0   0 
ext);
   set_smell("default", "The air smells fresh.");
   set_listen("default", "Your footsteps echo loudly in the chamber.");
   set_items( ([
                ({"bone", "bones"}):
"There are many bones here, most of which seem to have teeth marks on them.",
                ({"weapons", "rusty weapons", "rusted weapons"}):
       "Several rusted swords and daggers lie in a pile in one corner.",
                ({"ceiling", "stalactites"}):
"Thankfully, the ceiling is high, so the stalactites are far above your head.",
                ]) );
   set_exits( ([
                "north": PATH+"catac018",
                "southwest": PATH+"catac020",
                "southeast": PATH+"catac029",
                ]) );
   set_pre_exit_functions( ({"southwest"}), ({"go_southwest"}) );
   set_pre_exit_functions( ({"southeast"}), ({"go_southeast"}) );
}
 
int go_southwest() {
   if(present("skeleton warrior")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The skeleton warrior claws you in the face and pushes you back!");
      this_player()->add_hp(-5);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go southwest, but was struck in the face by the "+
        "skeleton warrior and was pushed back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
int go_southeast() {
   if(present("skeleton warrior")) {
      if(this_player()->query_invis()) return 1;
      if(this_player()->query_hiding() >= 50) return 1;
      if(this_player()->query_stealth() >= 75) return 1;
      write("The skeleton warrior claws you in the face and pushes you back!");
      this_player()->add_hp(-5);
      tell_room(this_object(), this_player()->query_cap_name()+
        " tried to go southeast, but was struck in the face by the "+
        "skeleton warrior and was pushed back!", ({ this_player() }) );
      return 0;
   }
   else
      return 1;
}
 
void reset() {
   object ob;
   ::reset();
 
   if(!present("skeleton warrior")) {
      ob = new(MON_PATH+"skelwarr");
      ob->move(this_object());
   }
}
