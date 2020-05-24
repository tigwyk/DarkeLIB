//      Wizard:  Khojem
//      s24.c

#include <std.h>
inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("read", "read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","plank");
      add_action("no_exit","north");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   P \n   \nDock Street");
    set("long","Dock Street extends east and west.  "+
      "The harbor is just to the south.  "+
      "A schooner is berthed just to the south and a plank leads off to it.  "+
      "The wooden boards beneath your feet creak with every footstep.  "+
      "Loud laughter emits from a shop to the north.\n   0\n   | \n0--@--0\n   P \n   \n"
    );
    add_exit("/d/khojem/port/shop/pub","north");
    add_exit("/d/khojem/port/room/s23","west");
    add_exit("/d/khojem/port/room/s25","east");
    add_exit("/d/khojem/port/room/ship1","plank");
    set_items(([
     ({ "sign" }) :
        "It is an old, weather-beaten sign.  Try reading it.",
     ({ "ship","schooner" }) :
        "The schooner is a worn ship, but appear still seaworthy.  "+
        "It has foremast and mainmast stepped near amidships.  "+
        "A wooden plank leads off to it.",
     ({ "plank" }) :
        "A weather-beaten, thick wooden plank leads south to a schooner.",
     ({ "shop","doorway" }) :
        "A broad doorway serves as an entrance to a place of business.  "+
        "A sign hangs above the doorway.",
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
    write("\n       Rusty Parrot\n");
	return 1;
}

