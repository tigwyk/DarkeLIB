// deadroom

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A spacious alcove");
    set("long", "This room is covered almost entirely in fresh blood.  "+
      "It appears to have once been a study of some sort, but now only "+
      "broken furniture and blood-soaked fabric remain."
  );
    add_item("furniture","The furniture has been smashed to pieces.");
    add_item("fabric","You see fabric still damp with blood.");
    add_exit("whall2","south");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear crunching.");
    new("/wizards/leander/area1/obj/deadman")->move(this_object());
}
void reset() {
  object mon;
  ::reset();
   if(!present("zombie"))
      new(A1MON+"zombie")->move(this_object());
}

