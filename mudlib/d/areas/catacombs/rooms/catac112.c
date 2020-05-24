/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void init() {
   ::init();
//   add_action("open_door", "open");
}
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The walls and floor of this circular chamber are polished so highly 
   that the light emanating from the torches causes the room to be 
   very brightly lit.  Sounds of shuffling feet and scraping claws 
   are audible, and seem to be coming from the floor of the chamber.  
   Passageways lead off to the southwest and southeast.
  
    @
   / \
  0   0  
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear the shuffling of feet nearby.");
   set_search("floor", "You find a hidden trap door in the floor!");
   set_search("default", "Something seems strange with the floor.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are highly polished for some reason.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac113",
                "southeast": PATH+"catac151",
                ]) );
}
 
void reset() {
   ::reset();
   remove_exit("trapdoor");
   if(!present("gold skeleton"))
      new(MON_PATH+"goldskel")->move(this_object());
}
 
int open_door(string str) {
   if(!str)
      return 0;
   if(str != "door" && str != "trap door") {
      notify_fail("Open what?\n");
      return 0;
   }
   message("info", "You bend down and open the trap door in the floor.",
           this_player());
   message("info", this_player()->query_cap_name()+" reaches down and "+
           "opens a trap door hidden in the floor!", this_object(),
           this_player());
   add_exit(PATH+"catac160", "trapdoor");
}
 
