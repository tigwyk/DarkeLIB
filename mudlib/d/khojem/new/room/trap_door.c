//      Wizard:  Khojem
//      Mage's Trapdoor
//      trap_door.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Underground Cavern");
    set("long", "The ladder leading through the trapdoor descends down "+
      "beyond the forest floor to a small, dark underground cavern.  "+
      "The cavern's walls seem to humm with a magical force."
    );
    add_exit("mage_hut","up");
    set_items(([
     ({ "cave" , "cavern" }) : "It's a small, dark cave.",
     ({ "wall", "walls" }) :
        "The wall is composed of dirt and clay, but humm oddly."
     ]));
    set_pre_exit_functions(({ "up" }),({ "go_up" }));
    set_smell("default", "The air smells dank and cold.");
    set_listen("default", "You hear a humming sound from all around.");
    new("/d/khojem/new/mon/evil_faerie")->move(this_object());
}

int go_up(){
    tell_room("/d/khojem/new/room/mage_hut","A trapdoor appears "+
      "out of it steps "+this_player()->query_cap_name()+".  The trapdoor "+
      "closes behind him.\n");
    return 1;
} 

