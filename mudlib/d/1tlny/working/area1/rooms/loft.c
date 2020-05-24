// loft

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A corner loft");
    set("long", "This large room serves as the mansion loft.  Little "+
      "is left in this room, and the floors are bare.  To your west "+
      "you can see an old fire place with a painting over it.  To the "+
      "north there is a large window set in the wall, and to the east "+
      "you can see a storage closet."
  );
    add_item("fire","This old fire place is empty.");
    add_item("window","Through the window you can see a castle set "+
      "across the forest.");
    add_item("painting","The painting seems to be of an elven man.");
    add_exit("din3","south");
    add_exit("storage","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear moaning.");
}
void reset() {
   if(!present("zombie"))
      new(A1MON+"zombie")->move(this_object());
      new(A1MON+"zombie")->move(this_object());
      new(A1MON+"zombie")->move(this_object());
}
