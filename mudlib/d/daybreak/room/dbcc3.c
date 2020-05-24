#include "../daybreak.h"
inherit "std/room";


void init(){
::init();
//  add_action("no_east", "east");
}
void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"dbcc4", "north");
    add_exit(ROOMS+"dbcc2","south");
//Broken room removed Tiny
    //add_exit("/d/damned/guilds/join_rooms/mercenary_join","east");
//Basic mapping added by Tiny 1/19/2020
    set("short","   0\n   | \n   @   \n   | \n   0\nCommerce Court");
    set("long","Commerce Court runs north-south through Daybreak Ridge.\n   0\n   | \n   @   \n   | \n   0\n");
}

int no_east(string str) {
        if(wizardp(TP)) { return 0; }
        if(TP->query_class() == "mercenary") { return 0; }
        if(TP->is_pet()) { return 0; }
//        if(TP->query_class() == "child") { return 0; }
        message("info", "The Mercenary Guild will be opening soon, stay tuned to the news for further info.", this_player());
        return 1;
}
