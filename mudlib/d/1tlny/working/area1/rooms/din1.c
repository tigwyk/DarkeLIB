// din 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A long dining hall");
    set("long", "This dining hall seems somewhat untouched.  The "+
      "typical table settings sit on top of a nondescript table "+
      "running the length of the room.  The hall continues to the "+
      "west, and a large chamber lies to the east.  The south you "+
      "see a boarded up doorway that once lead to the kitchen."
  );
    add_item("doorway","It looks as though somebody wanted to keep "+
      "someone, or some thing locked up.");
    add_item("settings","You see typical dinner settings.");
    add_item("chairs","You see many straight back chairs.");
    add_exit("nwchamber","east");
    add_exit("din2","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("table"))
      new(A1OBJ+"tablee")->move(this_object());
   if(!present("scout"))
      new(A1MON+"scout")->move(this_object());
}
