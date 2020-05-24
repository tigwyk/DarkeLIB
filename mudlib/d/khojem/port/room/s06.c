//      Wizard:  Khojem
//      s06.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nWharf Street");
    set("long", "Wharf Street and Noble Street intersect here.  Each street is "+
      "constructed of dry dirt that sends up small swirls of dust with every "+
      "footstep.  The great north wall of Vo'Sangor connects to a massive "+
      "escarpment to the northwest.  Hollowed out at the escarpment's base "+
      "is a small box-like canyon that you can see just to your west.  "+
      "Wharf Street continues south from this point and a tower of some sort "+
      "can be seen in that direction.\n   0\n   | \n0--@--0\n   | \n   0\n"
    );
    add_exit("/d/khojem/port/room/ngate","north");
    add_exit("/d/khojem/port/room/s07","south");
    add_exit("/d/khojem/port/room/r1","west");
    add_exit("/d/khojem/port/room/s15","east");
    set_items(([
     ({ "wall", "escarpment", "canyon" }) :
        "The city's north and west walls are fixed in a massive rock formation "+
        "with sheer cliffs just northwest of this location.  A small, concave "+
        "canyon can be seen to the west.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

