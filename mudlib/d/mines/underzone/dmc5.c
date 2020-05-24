//      From Maxwell's Underground mudlib
//        5th Room of Dwarf Mining/Crypt Zone

#include <std.h>
#include "under.h"
inherit "/std/vault";
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are in a musty burial chamber. A door leads out "
"of the chamber to the south. An archway leads to another chamber to "
"the east..");
    set("long", @ext You are standing in a musty burial chamber. Long cobwebs 
hang down in front of you. You can see another dark chamber to the east. 
You sense that this is a sacred place. Maybe you should leave.
  
    @--0
    |
    0
ext);
    set_exits( ({ UNDER+"dmc4",UNDER+"dmc6"}),
      ({ "south","east" }));
    set_items( ([
    "archway" : "The archway is made of stone, and is covered in mold."]));
    set_smell("default", "You can smell the foul stench of decay and "
    "mold.");
   set_door("door", UNDER+"dmc4", "south", 0);
   set_string("door", "close", "You pull against the heavy door "
      "until it slides shut with a loud groan.\n"); 
   set_string("door", "open", "You hear the heavy door groan as "
      "you push it open.\n");   
}
void look_at_door() {
   if(query_open("door")) write("The door has been pushed open.");
   else write("The door is tightly shut.");
}
void reset() {
    ::reset();
    set_open("door",0);
}


