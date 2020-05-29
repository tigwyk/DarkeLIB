//      From Maxwell's Underground mudlib
//        43rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;
int x;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing on a spiral staircase below the tomb. "
       "The slippery steps wrap around a tall stone column next to you, "
       "slowly winding down to the floor.");
    set("long", "You are standing on a spiral staircase that winds down "
       "below you. The slick steps are covered with dark mold and pieces "
       "of rotten material. You almost lose you balance several times.");
    set_exits( ({ UNDER+"dmc2"}),({ "down" }));
    set_items( ([
"pots" : "The large pots are still filled with a foul smelling liquid."]));
    set_smell("default", "You can smell the foul stench of decay and "
       "mold.");
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
    add_exit(UNDER+"dm43","up"); 
    x = 0;
    say("A loud grating sound rumbles through the room as "
     +this_player()->query_cap_name()+" pushes the heavy slab to the side, "
     "revealing an opening out of the tomb.\n"); 
    write("You push the stone slab to the side and reveal an opening "
      "out of the tomb.\n");
    present("tomb",find_object(UNDER+"dm43"))->auto_open();
    set("long", "You are standing on a spiral staircase that winds down "
      "below you. The slick steps are covered with dark mold and pieces of "
       "rotten material. You almost lose you balance several times.\n"
       "The large slab has been pushed aside.");
    return 1;
    }
 }
}
int otherside(){
   if(x == 1){
     add_exit(UNDER+"dm43","up"); 
     tell_room(UNDER+"dmc1","A loud grating sound rumbles through the "
"room as the heavy slab is pushed aside.");
    x = 0;
    return 1;
   }
}
void reset() {
   ::reset();
    x = 1;
    remove_exit("up");
    set("long", "You are standing on a spiral staircase that winds down "
"below you. The slick steps are covered with dark mold and pieces of "
"rotten material. You almost lose you balance several times.");
}


