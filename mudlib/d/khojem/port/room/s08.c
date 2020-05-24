//      Wizard:  Khojem
//      s08.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n0--@--0\n  /|\\ \n 0 0 0\nVo'Sangor Square");
    set("long", "Vo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "to the south. Wharf Street extends north from here.\n   0\n   | \n0--@--0\n  /|\\ \n 0 0 0\n"  
    );
    add_exit("/d/khojem/port/room/s07","north");
    add_exit("/d/khojem/port/room/s09","south");
    add_exit("/d/khojem/port/room/s03","west");
    add_exit("/d/khojem/port/room/s16","east");
    add_exit("/d/khojem/port/room/s04","southwest");
    add_exit("/d/khojem/port/room/s17","southeast");
    set_items(([
     ({ "sauare","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}
