//      Wizard:  Khojem
//      s11.c

#include <std.h>
inherit ROOM;

int no_exit() { return 1;}

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
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","plank");
      add_action("no_exit","west");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n0--@-p \n   | \n   0\nWharf Street");
    set("long","Wharf Street extends north and south.  "+
      "The harbor is just to the east and a finely, rigged ship is closeby.  "+
      "A tall tower is off to the north.  "+
      "The wooden boards beneath your feet creak with every footstep.  "+
      "Some sort of shop is to the west.  A sign is above the open doorway.\n   0\n   | \n0--@-p \n   | \n   0\n"
    );
    add_exit("/d/khojem/port/shop/tavern","west");
    add_exit("/d/khojem/port/room/s10","north");
    add_exit("/d/khojem/port/room/s12","south");
    add_exit("/d/khojem/port/room/mow","plank");
    set_items(([
     ({ "ship","finely rigged ship" }) :
        "The ship is a large man-o-war with tall masts and a high gunwhale.  "+
        "A wooden plank leads off to it.",
     ({ "plank" }) :
        "A weather-beaten, thick wooden plank leads east to a ship.",
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
     ({ "street","dirt street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
}

int read(string str) {
    write("\n           Sailor's Pleasure\n"+
      "  Owned and Operated by One-Eyed Sparkey\n");
	return 1;
}

