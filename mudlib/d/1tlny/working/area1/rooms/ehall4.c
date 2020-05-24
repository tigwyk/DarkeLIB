// ehall 4

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A stained-glass hallway");
    set("long", "This hallway turns from west to south.  To the east you "+
      "see a passage leading outside to the garden.  The stain-glass "+
      "continues to the south, and a well lit hallway begins to the west. "+
      "To the north you see a trophy room."
  );
    add_item("glass","You see brilliantly crafted stain glass windows.");
    add_exit("ehall3","south");
    add_exit("trophy2","north");
    add_exit("garden1","leave");
    add_exit("nhall4","west");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear crunching.");
}
void reset() {
   if(!present("hunter"))
      new(A1MON+"hunter")->move(this_object());
}
