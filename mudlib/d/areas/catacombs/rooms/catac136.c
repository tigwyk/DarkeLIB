/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The corridor suddenly comes to an end here, perhaps too suddenly.  
   The granite wall before you is polished so well that you can make 
   out part of your reflection.   The torch light provided by the small 
   torches mounted on the wall illuminates your face as you look over 
   the area.
   
    @
   / \
  0   0  
ext);
   set_smell("default", "The air smells of dust.");
   set_listen("default", "You hear someone sobbing to the southwest.");
   set_search("default", "You discover the southwestern wall to be an illusion!");
   set_items( ([
                ({"walls", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac148",
                "southeast": PATH+"catac135",
                ]) );
   set_invis_exits( ({"southwest"}) );
}
