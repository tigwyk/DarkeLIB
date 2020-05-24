// laboratory 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A creepy laboratory");
    set("long", @ext This laboratory is filled with many broken racks of 
      potions and strange components.  The lab continues to the 
      east and to the south.  There is a HUGE container set against 
      the wall here.

    @--0
    |
    0
ext);
    add_item("racks","They used to hold many potions.");
    add_item("container","This container reaches all the way up to "+
      "the ceiling.  It has been opened, and all that is left on the "+
      "inside is massive claw marks.");
    add_item("potions","You see broken glasses of strange mixtures.");
    add_item("components","You see disgusting pickled animal parts.");

    add_exit("lab1","east");
    add_exit("lab3","south"); 

    set_smell("default", "You smell strange chemicals.");
    set_listen("default", "You hear roaring.");
}
void reset() {
   ::reset();
   if(!present("w_scout")) {
      new(A1MON+"w_scout")->move(this_object());
   }
}
