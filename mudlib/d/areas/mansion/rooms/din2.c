// din 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A long dining hall");
    set("long", @ext This end of the hall appears to more disturbed.  A 
      statue that seems to have fallen from the balcony above has 
      shattered in the middle of the table.  To the north you notice 
      a small doorway.  To the east lies the rest of the dining hall.
    0   
    |   
    @--0 
ext);
    add_item("chairs","You see many straight back chairs.");
    add_item("balcony","The balcony above seems to have broken.");
    add_item("statue","The shattered remains of a statue are merely "+
      "rubble now.");
    add_exit("din1","east");
    add_exit("whall1","north");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("table"))
      new(A1OBJ+"tablew")->move(this_object());
}
