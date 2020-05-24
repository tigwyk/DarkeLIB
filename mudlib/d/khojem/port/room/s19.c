//      Wizard:  Khojem
//      s19.c

#include <std.h>
inherit ROOM;

int check_mobs();
int my_mob_filter(object mob);

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/port/mon/worker1")  
    return 1;                                        
  return 0;
}

void reset(){
  ::reset();
  if(!present("worker")) {
    if(check_mobs()<5)
      new("/d/khojem/port/mon/worker1")->move(this_object());
  }
}

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n0--@--0\n    \n   \nDock Street");
    set("long","Dock Street extends east and west.  "+
      "The harbor is just to the south.  A tall tower is off to the west.  "+
      "The wooden boards beneath your feet creak with every footstep.  "+
      "Some sort of shop is to the north.  A sign is above the open doorway.\n   0\n   | \n0--@--0\n    \n   \n"
    );
    add_exit("/d/khojem/port/room/master","north");
    add_exit("/d/khojem/port/room/s17","west");
    add_exit("/d/khojem/port/room/s23","east");
    set_items(([
     ({ "shop","doorway" }) :
        "A broad doorway serves as an entrance to a place of business.  "+
        "A sign hangs above the doorway.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
     ({ "sign" }) :
        "It is an old, weather-beaten sign.  Try reading it.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Dock Street","dock street","dock" }) :
        "Dock Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
}

int read(string str) {
    write("\n     Harbor Master, Vo'Sangor\n");
	return 1;
}

