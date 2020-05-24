// storage

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "A storage closet");
    set("long", "This storage closet seems to be empty.  The only "+
      "thing strange about this small room is a hole in the far "+
      "corner.");
    add_item("hole","The hole seems to drop about 10 feet down "+
      "into a hallway.");
    add_exit("loft","west");
    add_exit("whall3","hole");
 
    set_smell("default", "You rotting flesh.");
    set_listen("default", "You hear moaning.");
}
