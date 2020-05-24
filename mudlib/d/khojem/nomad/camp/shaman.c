//      Wizard:  Khojem
//      Shaman's Tent
//      shaman.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    if(!present("cleric"))
      new("/d/khojem/nomad/mon/nomad_cleric")->move(this_object());
    ::reset();
}

void create() {
    ::create();
    set_property("light", 5);
    set_property("indoors", 1);
    set_property("night light",-2);
    set("day long",
      "The daytime sun beating down on the tent's roof turns the tent into a "+
      "sweltering sauna.  "
      "This tent is relatively sparce of furnishings or worldy goods.  You have "+
      "entered the tent of the war cleric.  Her power and might are felt as you "+
      "enter the tent.\n"
   );
    set("night long",
      "A chillness envelopes you as you enter the tent.  "+
      "This tent is relatively sparce of furnishings or worldy goods.  You have "+
      "entered the tent of the war cleric.  Her power and might are felt as you "+
      "enter the tent.\n"
    );
    add_exit("/d/khojem/nomad/camp/center","southwest");
    set_items(([
     ({ "tent"  }) :  
        "The tent is a small dome-like tent.",
     ({ "floor", "sand" }) :
        "The tent was setup on a bare sandy floor."
    ]));
    set_smell("default", "A fresh smell fills the tent.");
    set_listen("default", "It is stone quiet here.");
}
