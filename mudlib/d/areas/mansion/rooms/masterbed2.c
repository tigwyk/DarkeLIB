// master bed 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The master bedroom");
    set("long", @ext This end of the bedroom has a small night stand 
      set next to a large bed.  To the west the bedroom continues.

 0--@
ext);
    add_item("mirror","You see a strange distortion of yourself.");
    add_item("stand","You see a small night stand with many papers "+
      "on it.");
    add_item("papers","The papers seem to be some sort of formula.");
    add_exit("masterbed1","west");
 
    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("masterbed")) {
      new(A1OBJ+"masterbed")->move(this_object());
   }
}
