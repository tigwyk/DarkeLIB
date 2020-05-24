// carebed1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The caretaker's bedroom");
    set("long", "This small bedroom contains an equally small bed.  "+
      "A large dresser has been overturned in the middle of the room.  "+
      "Towards the north you can see a closet."
  );
    add_item("dresser","The dresser looks as though it was smashed open.");
    add_exit("carecloset","north");
    add_exit("nechamber","west");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
  object mon;
  ::reset();
   if(!present("bed"))
      new(A1OBJ+"smallbed")->move(this_object());
}
