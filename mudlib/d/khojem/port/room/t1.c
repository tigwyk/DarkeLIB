//      Wizard:  Khojem
//      t1.c

#include <std.h>
inherit "std/vault";

void create() {
    ::create();
    set_property("light", -1);
    set_property("night light",-2);
    set_property("indoors", 1);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   u \n   @--0\n     \n    \nMage's Keep");
    set("long", "This is the base of a large, circular stone tower.  A lighted "+
      "shop is to the east.  A dark"
      "spiral, stone staircase leads upwards.  The arched gateway to the city "+
      "is just towards the north.\n   0\n   u \n   @--0\n     \n    \n"
    );
    add_exit("/d/khojem/port/room/t2","up");
    add_exit("/d/khojem/port/room/wgate","north");
    add_exit("/d/khojem/port/shop/zalrag_shop","east");
    set_door("east door", "/d/khojem/port/shop/zalrag_shop", "east",
      "a non-existent key");
	set_open("east door", 1);
    set_locked("east door", 0);
    set_open_function("open_door", "20:30:00");
    set_close_function("close_door", "06:30:00");
    set_items(([
     ({ "door", "east door" }) : "It looks like a sturdy door.",
     ({ "arched gateway", "gateway", "gate" }) :
        "Its a dusty little road covered with a stone, arched roof",
     ({ "stone tower", "tower", "shop" }) :
        "The base of the tower is constructed of rough, hewned stones "+
        "built in a circle.  No form of lighting is available, but some "+
        "light can be seen cast from a shop towards the east.",
     ({ "staircase", "stone staircase", "stairs" }) :
        "The stone staircase is very dark and spirals upward from the base "+
        "of the tower.  Its steps are worn from repeated use, but many "+
        "cobwebs can be seen draped across its path.",
     ({ "steps", "cobweb", "cobwebs" }) :
        "The steps lead upwards into the tower.  The once silvery cobwebs "+
        "are coated with much dust.  Obviously, the staircase has not been "+
        "used recently.",
    ]));
    set_smell("default", "A wet dankness fills the air.");
    set_listen("default", "It is quiet here.");
}
void close_door() {
  call_other("/d/khojem/port/shop/zalrag_shop", "close_door");
  return;
}

void open_door() {
  call_other("/d/khojem/port/shop/zalrag_shop", "open_door");
  return;
}

