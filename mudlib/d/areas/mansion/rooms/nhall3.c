// nhall 3

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A well lit hallway");
    set("long", @ext This hallway continues to the east and the west.  
      To the south you can see a passage leading towards a set of 
      stairs.
    0   
    |   
 0--@--0
    |
    0  
ext);
    add_exit("nstairs1","south");
    add_exit("nhall4","east");
    add_exit("nhall2","west");
    add_exit("guestbed","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("zombie")) {
      new(A1MON+"zombie")->move(this_object());
      new(A1MON+"zombie")->move(this_object());
   }
}
