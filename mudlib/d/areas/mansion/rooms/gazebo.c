// gazebo

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "A tall atrium");
    set("long", @ext As you look around gazebo from it's steps you can see 
      a path leading in the distance through the forest.  Movements 
      fill the bushes and shrubs all around you.  To the north lies a 
      garden path.
    0   
    |   
    @ 
ext);
    add_item("shrubs","The bushes and shrubs shake every so often.");
    add_item("bushes","The bushes and shrubs shake every so often.");
    add_exit("garden2","north");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear howling nearby.");
}
void reset() {
   if(!present("hunter"))
      new(A1MON+"hunter")->move(this_object());
}
