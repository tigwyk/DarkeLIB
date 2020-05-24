// atrium

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "A tall atrium");
    set("long", "As you stare up through the atrium you notice a large "+
      "hole in the glass about 20' up.  The ground beneath you is soggy "+
      "from a recent rain.");
    add_item("hole","The glass looks as though it were broken from the "+
      "inside.");
    add_exit("tool","north");
    add_exit("music","east");
 
    set_smell("default", "You smell the night air.");
    set_listen("default", "You hear nothing.");
}
void reset() {
   if(!present("plant"))
      new(A1MON+"plant")->move(this_object());
   if(!present("raven"))
      new(A1MON+"raven")->move(this_object());
      new(A1MON+"raven")->move(this_object());
}
