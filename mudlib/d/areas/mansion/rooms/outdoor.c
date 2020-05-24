// outdoor

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "Outside a large mansion");
    set("long", @ext You stand on a dark, winding trail.  It narrows 
      as it slithers off to the south into the thicker forest.  
      There is a large door to the north at the base of a very 
      large mansion.
      
      enter   
    @
    |
    0  
ext);
    add_item("trail","The trail looks as though it were once well worn.");
    add_item("forest","The dark forest looms all around you.");
    add_item("mansion","A three story mansion towers over you.");
    add_exit("indoor","enter");
    add_exit("trail5","south");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear howling in the distance.");
}
void reset() {
   ::reset();
   if(!present("dog")) {
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
   }
}
