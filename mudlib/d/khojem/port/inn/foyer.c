#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The Bonny Lass Inn foyer");
    set("long",
        "This is the foyer of the inn.  You see hallways leading "+
        "to the north, east, and south.  To the southwest is the front "+
        "desk.  You see a staircase leading up.");
    add_exit("/d/khojem/port/inn/main_room", "southwest");
    add_exit("/d/khojem/port/inn/foyer2", "up");
    add_exit("/d/khojem/port/inn/hall_10", "north");
    add_exit("/d/khojem/port/inn/hall_11", "east");
    add_exit("/d/khojem/port/inn/hall_12", "south");
    return;
}


