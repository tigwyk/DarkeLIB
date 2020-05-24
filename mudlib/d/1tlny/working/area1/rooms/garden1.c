// garden 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "A garden path");
    set("long", "You now stand outside the large mansion on a garden "+
      "path leading to the south.  To the west you can see a doorway "+
      "leading back to the mansion, and to the east you can see an "+
      "iron fence blocking off the forest."
  );
    add_item("fence","This iron fence seems rusted but strong.");
    add_exit("garden2","south");
    add_exit("ehall4","enter");

    set_smell("default", "You smell death and decay.");
    set_listen("default", "You hear howling and trickling water.");

    new("/d/nocte/kuril/misc/fountain")->move(this_object());
}
void reset() {
   if(!present("plant"))
      new(A1MON+"plant")->move(this_object());
}
