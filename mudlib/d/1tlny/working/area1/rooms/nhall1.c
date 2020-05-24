// nhall 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A well lit hallway");
    set("long", "Here the hallway turns to the south, and continues "+
      "off to the east.  To the north you see a large set of double "+
      "doors leading to one of the master bedrooms."
  );
    add_exit("whall4","south");
    add_exit("nhall2","east");
    add_exit("masterbed1","north");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear crunching.");
}
void reset() {
   ::reset();
   if(!present("hunter")) {
      new(A1MON+"hunter")->move(this_object());
      new(A1MON+"hunter")->move(this_object());
   }
}
