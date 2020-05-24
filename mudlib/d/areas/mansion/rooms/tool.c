// tool

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "An equipment room");
    set("long", @ext This tool shed of sorts holds most of the equipment 
      needed for maintaining the atrium, garden, and rest of the 
      mansion.  Most of it sits unused under many spider webs.

    @
    |
    0
ext);
    add_item("equipment","There is nothing of use here.");
    add_item("webs","The webs cover everything.");
    add_exit("atrium","south");
 
    set_invis_exits( ({"north"}) );
    set_smell("default", "You smell nothing.");
    set_listen("default", "You hear squeaking.");
}
void reset() {
   if(!present("rat"))
      new(A1MON+"rat")->move(this_object());
}
