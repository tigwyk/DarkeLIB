// din 4

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "Above the dining hall");
    set("long", "You are now on the second floor of the dining "+
      "room.  Below you lies a large table that stretches the "+
      "entire length of the hall from east to west."
  );
    add_item("below","You see a long dining room below.");
    add_item("table","You see a long dining room table.");
    add_exit("nwsecond","east");
    add_exit("din3","west");   

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   ::reset();
   if(!present("zombie")) {
      new(A1MON+"zombie")->move(this_object());
      new(A1MON+"zombie")->move(this_object());
   }
}
