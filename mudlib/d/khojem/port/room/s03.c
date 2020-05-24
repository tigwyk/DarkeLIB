//      Wizard:  Khojem
//      s03.c

#include <std.h>
inherit "std/vault";

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("read", "read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","west");
      add_action("no_exit","north");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n0--@--0\n   |\\ \n   0 0\nVo'Sangor Square");
    set("long", "Vo'Sangor Square is the merchant place of all DarkeMud. "+
      "Here all may purchase the fine goods brought in at this town's seaport.  "+
      "Of course, with all rare items they come with a cost.  A tall tower is "+
      "to the southeast.  Shops can be seen north and west of here.  A sign "+
      "hangs above each doorway.\n   0\n   | \n   @--0\n   |\\ \n   0 0\n"  
    );
    add_exit("/d/khojem/port/shop/droblek_shop","north");
    add_exit("/d/khojem/port/room/s04","south");
    //add_exit("/d/khojem/port/shop/gedrak_shop","west");
    add_exit("/d/khojem/port/room/s08","east");
    add_exit("/d/khojem/port/room/s09","southeast");
    set_door("north door", "/d/khojem/port/shop/droblek_shop", "north",
      "a non-existent key");
	set_open("north door", 1);
    set_locked("north door", 0);
    set_open_function("open_door", "06:15:00");
    set_close_function("close_door", "22:15:00");
    set_items(([
     ({ "square","merchant square" }) :
        "Its a dusty opening in the center of town.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
     ({ "door", "north door" }) : "It looks like a sturdy door.",
     ({ "shop","doorway" }) :
        "Doorways to two grand shops open north and west.",
     ({ "sign", "signs" }) :
        "Simple signs hang above each shop doorway.  Maybe you can "+
        "'read sign west' and 'read sign north'?"
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The noise of a busy town surrounds you.");
}

int read(string str) {
  if(str=="sign west"){
    write("\n    Gedraks's Goods and Supplies\n");
	return 1;
  }
  if(str=="sign north"){
    write("\n    Droblek's Caravan Outfitters\n");
    return 1;
  }
  return 0;
}
void close_door() {
  call_other("/d/khojem/port/shop/droblek_shop", "close_door");
  return;
}

void open_door() {
  call_other("/d/khojem/port/shop/droblek_shop", "open_door");
  return;
}


