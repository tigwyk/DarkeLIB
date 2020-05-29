//      From Maxwell's Underground mudlib
//        37th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a long stone corridor. "
"The corridor leads to the north and the south.\n");
    set("long", 
"You are standing in a long stone corridor. The walls are made of solid "
"blocks of stone. Some of the ancient blocks have cracked over the ages, "
"but the structure of the temple still looks strong.\n");
    set_exits( ({ UNDER+"dm34" }),({ "south" }));
    set_items( ([
       "blocks" : "The huge blocks must weigh several tons."]) );
    set_smell("default", "You can smell a mold and decay in the "
        "passage.");
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
   tell_room(UNDER+"dm37","A large solid stone slab lowers down and blocks "
     "the southwest exit");
   remove_exit("north");
   return 1;
}
int raise(){
   tell_room(UNDER+"dm37","A large solid stone slab rises up, revealing "
             "another exit to the north!");    
   add_exit( UNDER+"dm40","north");
   return 1;
}


