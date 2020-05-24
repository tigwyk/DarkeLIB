#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The Bonny Lass Inn foyer");
    set("long",
        "You reach a second-story landing.  You see hallways leading "+
        "to the north, east, and south.  You see a staircase leading down.");
    add_exit("/d/khojem/port/inn/foyer", "down");
    add_exit("/d/khojem/port/inn/hall_20", "north");
    add_exit("/d/khojem/port/inn/hall_21", "east");
    add_exit("/d/khojem/port/inn/hall_22", "west");
    return;
}


