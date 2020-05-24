//      From Maxwell's Underground mudlib
//        35th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;
int x;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a long stone passage that leads to "
"the southwest and the northeast.\n");
    set("long", @ext You are standing in a long passage that leads to the 
southwest and the northeast. The floor of the passage is cracked and 
broken in several places. Many years of errosion has caused major 
damage in this area of the temple.
      0  
     /   
    @
ext);
    set_exits( ({UNDER+"dm34" }),
               ({"northeast" }));
    set_items( ([
       "floor" : "The stone floor is cracked and busted in several "
                 "spots."]));
    set_smell("default", "The dust floating through the air is making "
                 "it hard to breathe.");
    set_property("x",1);
}
void init(){
   ::init();

   if( (this_object()->query_property("x")) == 2){
     this_object()->set_property("x",3); 
     call_out("raise",3,this_object());
   }

}  
int lower(){
   tell_room(UNDER+"dm35","A large solid stone slab lowers down and blocks "
     "the southwest exit");
   remove_exit("southwest");

   return 1;
}
int raise(){
   tell_room(UNDER+"dm35","A large solid stone slab rises up, revealing "
             "another exit to the southwest!");    
   add_exit( UNDER+"dm38","southwest");
   return 1;
}
mixed query_x(){
    return ("value of x is "+x);
}

