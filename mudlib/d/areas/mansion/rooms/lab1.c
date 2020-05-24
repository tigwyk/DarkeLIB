// laboratory 1

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "An eerie laboratory");
    set("long", @ext This laboratory is filled with many racks of 
      potions and strange components.  To the east you see a 
      reception area, and to the west the lab continues.

 0--@--0
ext);
    add_item("racks","They hold many useless potions.");
    add_item("potions","You see murky mixtures.");
    add_item("components","You see disgusting pickled animal parts.");
    add_exit("outlab","east");
    add_exit("lab2","west"); 

    set_smell("default", "You smell strange chemicals.");
    set_listen("default", "You hear nothing.");
}
void reset() {
   ::reset();
   if(!present("hunter")) {
      new(A1MON+"hunter")->move(this_object());
   }
}
