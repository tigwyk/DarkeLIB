//      From Maxwell's Underground mudlib
//        44th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;
int x;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small stairway inside the tomb. "
"The stairs rise to a large stone slab above you and continue down into "
"another chamber.");
    set("long", "You are standing in a small stairway inside the tomb. The "
"stairs rise to a large stone slab in the wall above you and continue "
"lower into the tomb. It looks like the staircase opens into another "
"chamber below you.");
    set_exits( ({ UNDER+"dm34"}),
      ({ "down" }));
    set_items( ([
       "stairs" : "The solid stone steps are slick and covered with "
       "slime.",
       "slab" : "The large slab looks like it is loose."]) );
       set_smell("default", "You can smell mold and decay in the air.");
     x = 1;
}
void init() {
     ::init();
     add_action("push","push");
}
int push(string str){
 if(str == "slab") {
   if(x == 0) {
   write("The slab has already been pushed aside.");
   return 1;
   }
   if(x == 1) {
    add_exit(UNDER+"dm42","up"); 
    x = 0;
    say("A loud grating sound rumbles through the room as "
+this_player()->query_cap_name()+" pushes the heavy slab to the side, "
"revealing an opening out of the tomb.\n"); 
    write("You push the stone slab to the side and reveal an opening "
"out of the tomb.\n");
    present("tomb",find_object(UNDER+"dm42"))->auto_open();
    set("long", "You are standing in a small stairway inside the tomb. The "
"stairs rise to the exit above you and continue lower into the tomb. It "
"looks like the staircase opens into another chamber below you.\n"
"The large slab has been pushed aside.");
    return 1;
    }
 }
}
int otherside(){
   if(x == 1){
     add_exit(UNDER+"dm42","up"); 
     tell_room(UNDER+"44","A loud grating sound rumbles through the "
"room as the heavy slab is pushed aside.");
    x = 0;
    return 1;
   }
}
void reset() {
   ::reset();
    x = 1;
    remove_exit("up");
    set("long", "You are standing in a small stairway inside the tomb. The "
"stairs rise to the exit above you and continue lower into the tomb. It "
"looks like the staircase opens into another chamber below you.");
}
