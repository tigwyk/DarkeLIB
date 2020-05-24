// laboratory 3

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A disturbing laboratory");
    set("long", @ext This section of the lab has been completely 
      destroyed.  What is left seems to have been turned into some 
      sort of a lair for something very large.  The less disturbed 
      section of the lab lies to the north, and a tight passage is 
      set in the east wall.
    0   
    |   
    @
     crack
    
ext);

    add_exit("labsecret","crack");
    add_exit("lab2","north"); 

    set_smell("default", "You smell strange chemicals.");
    set_listen("default", "You hear nothing.");
}
void reset() {
   ::reset();
   if(!present("creation")) {
      new(A1MON+"creation")->move(this_object());
   }
}
