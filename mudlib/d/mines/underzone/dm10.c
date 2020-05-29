//      From Maxwell's Underground mudlib
//        10th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit "std/vault";


void reset() {
    object mon;
    ::reset();
    set_open("door",0);
    set_locked("door",1);
    set_lock_level("door",23);
    (UNDER+"dm11")->set_open("door",0);
}
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground mine");
    set("long", 
"You are standing in a small alcove east of the connection chamber. "
"Water slowly rolls down the walls in little streams, soaking the moldy "
"staw that is lining the floor. You can see faint seams of mineral "
"deposits in the walls.\nIn front of you is a solid looking oak door, "
"bolted to a support timber by several large steel hinges." 
       );

    set_exits( ({ UNDER+"dm9f", UNDER+"dm11" }),
      ({ "west", "door" }));
   set_door("door", UNDER+"dm11", "door", "mine key");
   set_open("door",0);
   set_locked("door",1);
    set_lock_level("door",23);
   set_string("door", "close", "You pull against the heavy door "
      "until it slides shut with a loud groan.\n"); 
   set_string("door", "open", "You hear the heavy door groan as "
      "you push it open.\n");   
   set_items( ([
       "door" : (: call_other, this_object(), "look_at_door" :),
       "hinges" : "The steel hinges look like they were made by a master "
       "craftsman.",
      ]) );
}
void look_at_door() {
   if(query_open("door")) write("The door has been pushed open.");
   else write("The door is tightly shut.");
}

