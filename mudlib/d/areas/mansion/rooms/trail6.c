// trail 6

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A small clearing");
    set("long", @ext Before you lies a slight opening in the forest.  As 
      you look around you notice blood covering most of the grass in 
      the small clearing, and various body parts strewn about.

 0--@
      
ext);
    add_item("grass","It is soaked in fresh blood.");
    add_item("parts","These disgusting parts seem to be from a human.");
    add_exit("trail5","west");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear growling all around you.");
}
void reset() {
   ::reset();
   if(!present("dog")) {
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
      new(A1MON+"dog")->move(this_object());
   }
}
