// swsecond

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "The southwest corner of the second floor");
    set("long", "You are standing on a balcony overlooking the "+
      "the large chamber below.  The path around the balcony "+
      "continues to the north."
  );
    add_exit("nwsecond","north");

    set_smell("default", "You smell nothing.");
    set_listen("default", "You hear distant footsteps.");
}
void reset() {
   if(!present("scout"))
      new(A1MON+"scout")->move(this_object());
}
