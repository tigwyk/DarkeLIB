//      From Maxwell's Underground mudlib
//        11th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit "/std/vault";

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "You are standing at the top of a long stairway.");
   set("long", 
    "You are standing at the top of a long stairway. The staircase "
    "stretchs down several hundred feet before connecting to a lower "
    "tunnel. The stone steps glisten slightly as the light, from several "
    "torches mounted along the stairway, reflects off the pooling water. "
    "Evidently the combination of damp air and the water trickling down "
    "the walls keeps the stairs fairly wet.\n" 
    "There is a large door to the west.");
   set_exits( ({ UNDER+"dm10", UNDER+"dm12" }),
      ({ "door", "east" }));
   set_items( ([
       "door" : (: call_other, this_object(), "look_at_door" :),
       "water" : "There must be an undergroung spring nearby.",
       "torches" : "The torches are attached to the wall by stong "
       "steel torch holders.",]) );
   set_door("door", UNDER+"dm10", "doorway", 0);
   set_string("door", "close", "You pull against the heavy door "
      "until it slides shut with a loud groan.\n"); 
   set_string("door", "open", "You hear the heavy door groan as "
      "you push it open.\n");   
    set_pre_exit_functions(({"door" }), ({"mob_check"}) );
}
void look_at_door() {
   if(query_open("door")) write("The door has been pushed open.");
   else write("The door is tightly shut.");
}
void reset() {
    ::reset();
    set_open("door",0);
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet())
      return 1;
    
}

