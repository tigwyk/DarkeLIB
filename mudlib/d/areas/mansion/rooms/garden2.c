// garden 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "A garden path");
    set("long", @ext You are standing on a garden path outside the large 
      mansion.  To the east you see an iron fence that keeps out the 
      thick forest.  To the north you see the path continue, and to 
      the south you can see a gazebo.
    0   
    |   
    @
    |
    0  
ext);
    add_item("fence","This iron fence seems rusted but strong.");
    add_exit("gazebo","south");
    add_exit("garden1","north");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear howling nearby.");
}
void reset() {
   ::reset();
   if(!present("dog")) {
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
   }
}
