//      Wizard:  Khojem
//      MD-Palace Guard Room
//      md_plguard.c

#include <std.h>

inherit ROOM;


void reset() {
   ::reset();
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
   new("/d/khojem/zone/mon/plguard3")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no magic",1);
    set("short", "Palace Guard");
    set("long", "Before you stands a large gate.  The ground has changed "+
      "from a rough-hewn stone to a finely, masoned hardstone with a glossy "+
      "finish.  The walls appear to be a white alabaster and curve to an "+
      "archway only a few inches over your head.  This area is quite cramped "+
      "and the walls seem to emit a strange, unwavering humming sound."
   );
    add_exit("md_way","east");
    set_property("no magic",1);
    set_item_descriptions( ({ "gate" }), ({ "The gate appears to be made of "+ 
     "a very strong metal and emits a strange, high pitched humming sound."
}));
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a low pitched humming sound that seems"+
      " to be coming from all around you.");
}
