/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This secret room is very small and contains only a single item: 
   a large mirror that sits in one corner.  Torches are bolted to the 
   wall and provide ample light to see.  As you gaze in the mirror, 
   you do not see your reflection, but the image of a chamber very much 
   like the one you are in now!
  0    
   \   
    @
ext);
   set_smell("default", "The air smells stale.");
   set_listen("default", "You hear banging to the northwest.");
   set_items( ([
                "mirror":
      "The image in the mirror wavers slightly when you gaze into it.  Maybe "+
      "you could try to 'enter' the mirror...",
                ({"torch", "torches"}):
      "The torches are firmly affixed to the walls.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac031",
                ]) );
}
 
void init() {
   ::init();
   add_action("enter", "enter");
}
 
int enter(string str) {
   if(!str) {
      write("Enter what?\n");
      return 1;
   }
   if(str == "mirror" || str == "portal") {
      write("%^BOLD%^%^CYAN%^You enter the mirror and are transported somewhere!");
      this_player()->move_player(PATH+"catac034");
      tell_room(this_object(), this_player()->query_cap_name()+
         " enters the mirror and disappears!", ({ this_player() }) );
      return 1;
   }
}
