//      Wizard:  Khojem
//      s14.c

#include <std.h>
inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","down");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
//Basic mapping added by Tiny 1/19/2020
    set("short", "   0\n   | \n   @   \n   d \n   \nWharf Street");
    set("long","Wharf Street ends here and extends north.  "+
      "The harbor is just to the east and south.  "+
      "The wooden boards beneath your feet creak with every footstep.  "+
      "Far to the south is a breakwater that protects the small harbor "+
      "from winter storms and reduces chop.\n   0\n   | \n   @   \n   d \n   \n"
    );
    add_exit("/d/khojem/port/room/s13","north");
    add_exit("/d/khojem/port/room/h4","down");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
     ({ "breakwater" }) :
        "The breakwater runs east to west and is constructed of huge rocks.  "+
        "It must have taken years to construct the breakwater, but Vo'Sangor "+
        "now benefits from a safe-harbor port.",
     ({ "ladder" }) :
        "It is a simple wooden ladder that leads down from the edge of the "+
        "dock to the water's surface a few feet below.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
}

int go_down() {
    write("Khojem suddenly materializes from the air and says,\n"+
      "     'I haven't implemented the water code yet.  Hang on!'\n");
    return 0;
}

