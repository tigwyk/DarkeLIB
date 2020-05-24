//      Wizard:  Khojem
//      orc3
//      orc3.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->chk_my_mon()) {
      add_action("no_exit","south");
      add_action("no_exit","east");
      add_action("no_exit","west");
    }
}

void reset() {
	::reset();
    if (!present("half-orc guard" , this_object()) ) {
        new("/d/khojem/new/mon/orc_guard")->move(this_object());
        new("/d/khojem/new/mon/orc_guard")->move(this_object());	  
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "   0\n   | \n0--@--0\n   p \n   0\nCentral Meeting Chamber");
    set("long", "Suddenly you emerge from the narrow passage to a "+
      "large, well-lit chamber.  The chamber is a large oval-shaped "+
      "cavern with a huge pit in the center.  This chamber "+
      "serves as a central meeting area for the cave-dwelling "+
      "Half-Orc clan.\n   0\n   | \n0--@--0\n   p \n   0\n"
    );
    add_exit("orc2","north");
    add_exit("orc4","west");
    add_exit("orc6","south");
    add_exit("orc7","east");
    add_exit("pit","pit");
    set_pre_exit_functions(({"pit"}),({"go_pit"}));
    set_items(([
     ({ "cave","cavern", "chamber", "meeting", "meeting room" }) :
        "This large area affords you with plenty of space to "+
        "maneuver for a fight.  But you would still prefer to be "+
        "outside in the open air.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.",
     ({ "pit", "fire" }) : 
        "The pit contains a large fire fueled by hardwood logs "+
        "from the surrounding forests.  The fire rests in a depression "+
        "a few feet below the surface of the chamber's floor.  High "+
        "above the cavern's chamber a hole allows the smoke to exit.  "+
        "The fire's logs burn in a hot, blue flame."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "You can hear the pit fire burning with "+
      "intensity.");
}

int go_pit(){
  write("The hot, blue flame flickers across your skin singeing "+
    "your eyebrows.  You quickly jump out of the pit.\n");
  this_player()->add_hp(-50);
  return 0;
}
