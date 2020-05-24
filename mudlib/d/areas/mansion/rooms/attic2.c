// attic 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "An old attic");
    set("long", @ext This old attic is stocked with old crates that look 
      as though they were looted long ago.  Wooden beams hold up the 
      ceiling above your head, and a wooden floor below you creaks 
      with every step.  To the south the attic continues.
   
    @
    |
    0  
ext);
    add_item("crates","You see empty crates.");
    add_item("beams","These old support beams still seem sturdy.");
    add_item("floor","The rotten floor looks as though it will hold.");
    add_exit("attic1","south");

    set_smell("default", "You smell mold and mildew.");
    set_listen("default", "You hear gnawing.");
}
void reset() {
   if(!present("rat"))
      new(A1MON+"rat")->move(this_object());
      new(A1MON+"rat")->move(this_object());
      new(A1MON+"rat")->move(this_object());
   if(!present("scout"))
      new(A1MON+"scout")->move(this_object());
}
