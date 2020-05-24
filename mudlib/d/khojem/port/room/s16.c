//      Wizard:  Khojem
//      s16.c

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   \n     \n0--@   \n  /| \n 0 0\nVo'Sangor Square");
    set("long", "Vo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "to the southwest.\n   \n     \n0--@   \n  /| \n 0 0\n"  
    );
    add_exit("/d/khojem/port/room/s17","south");
    add_exit("/d/khojem/port/room/s08","west");
    add_exit("/d/khojem/port/room/s09","southwest");
    set_items(([
     ({ "sauare","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}
