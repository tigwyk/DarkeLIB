// master bed 1

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The master bedroom");
    set("long", @ext This large room was once well decorated with fine 
      rugs and furniture, now overturned and covered with disgusting 
      bits of flesh and unknown substances.  A large bed can be seen 
      towards the east end of the chamber, and a hallway lies to 
      the south through a doorway.

    @--0
    |
    0
ext);
    add_item("rugs","They have brownish-red streaks on them.");
    add_item("furniture","There is nothing here of interest.");
    add_item("substances","You can't imagine where this goo came from.");
    add_exit("nhall1","south");
    add_exit("masterbed2","east"); 

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear moaning.");
}
void reset() {
   ::reset();
   if(!present("zombie")) {
      new(A1MON+"bigzombie")->move(this_object());
   }
}
