// ehall 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A stained-glass hallway");
    set("long", @ext This hallway leads from north to south.  To the east 
      the wall is made up almost entirely of fine stained glass.  Part 
      of the glass appears to have been broken from the outside here.
    0   
    |   
    @
    |
    0  
ext);
    add_item("glass","You see broken stained glass on the floor.");
    add_exit("ehall1","south");
    add_exit("ehall3","north");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear howling nearby.");
}
void reset() {
   ::reset();
   if(!present("dog")) {
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
   }
}
