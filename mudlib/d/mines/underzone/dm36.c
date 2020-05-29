//      From Maxwell's Underground mudlib
//        36th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a long corridor that leads "
"to southeast and the northwest.");
    set("long", "You are standing in a long corridor. The walls are made "
"of solid stone blocks that are stacked all the way to the ceiling. Small "
"torch stands were once stuck in the blocks, but they have been removed "
"long ago and all that remains are the holes.");
    set_exits( ({ UNDER+"dm34" }),({ "northwest" }));
    set_items( ([
      "holes" : "The small holes were carved into the solid rock."]) );
    set_smell("default", "You can smell the mold and dust floating "
              "through the air.");
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
   tell_room(UNDER+"dm36","A large solid stone slab lowers down and blocks "
     "the southwest exit");
   remove_exit("southeast");
   return 1;
}
int raise(){
   tell_room(UNDER+"dm36","A large solid stone slab rises up, revealing "
             "another exit to the southeast!");    
   add_exit( UNDER+"dm39","southeast");
   return 1;
}



