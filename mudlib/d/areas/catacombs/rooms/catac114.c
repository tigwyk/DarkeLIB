/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   As you gaze up at the high ceiling of the room, you shudder for a moment 
   when you spot the large stalactites hanging above your head.  There are 
   a number of small stalagmites pointing towards the ceiling and look 
   surprisingly sharp.  Passageways leave this room to the northwest, 
   south, and east.
  0    
   \   
    @--0
    |
    0   
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_search("default", (: call_other, this_object(), "search_area" :) );
 
   set_items( ([
                "stalactites":
        "Like all stalactites, these ones hang from the ceiling.",
                "stalagmites":
        "The stalagmites protrude from the floor and appear to be quite sharp.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac125",
                "east": PATH+"catac113",
                "south": PATH+"catac153",
               ]) );
}
 
void search_area() {
   string str;
 
   if((string)this_player()->query_gender() == "female")
      str = "her";
   else
      str = "him";
 
   message("info", "You search the floor and cut yourself on one of the stalagmites!",
                   this_player());
   message("info", this_player()->query_cap_name()+" searches the floor and cuts "+
                   str+"self on a stalagmite!", this_object(), this_player());
   this_player()->add_hp(-1*(5+random(5)));
}
