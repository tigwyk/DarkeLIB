/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 3);
   set("short", "Dark Dungeon");
   set("long",@ext
   In the center of this brightly-lit chamber sits a large mirror.  As 
   you gaze into the mirror, you do not see your reflection, but an 
   image of the inside of a crumbling crypt!  In fact, it appears to 
   be the location of the entrance to these acursed catacombs!
    0   
    |   
    @ 
ext);
   set_smell("default", "The air is very dry.");
   set_listen("default", "You hear evil laughter to the north.");
   set_items( ([
                "mirror":
        "In the mirror you see the image of a crumbling crypt!  Maybe "+
"You could try to 'enter' the mirror...",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The large torches that are affixed to the wall provide a good deal of light.",
                ]) );
   set_exits( ([
                "north": PATH+"catac205",
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
      write("You enter the mirror and are transported somewhere!");
      this_player()->move(PATH+"catac000");
      tell_room(this_object(), this_player()->query_cap_name()+
         " enters the mirror and disappears!", ({ this_player() }) );
      return 1;
   }
}
