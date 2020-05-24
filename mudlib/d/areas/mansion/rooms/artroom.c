// artroom

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A pillaged art room");
    set("long", @ext As you look around you notice broken sculptures and 
      torn paintings that at one time were probably worth something.  
      Now there is nothing of any interest left here.

 0--@--0
ext);
    add_item("paintings","You see many faded and trashed paintings.");
    add_exit("sechamber","west");
    add_exit("ehall1","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear howling nearby.");
}

void reset() {
  object mon;
  ::reset();
  if(!present("zombie"))
      new(A1MON+"zombie")->move(this_object());
  if(!present("sculpture"))
      new(A1OBJ+"sculpture")->move(this_object());
}
