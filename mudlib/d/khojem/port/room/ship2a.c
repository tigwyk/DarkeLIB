//      Wizard:  Khojem
//      ship2a.c

#include <std.h>
inherit ROOM;

void reset() {
    ::reset();
  if(!present("sailor")) {
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 0);
    set_property("night light",-1);
    set_property("indoors", 1);
    set("short", "Below deck on a pirate schooner");
    set("long","The below decks of the pirate schooner is filthy.  "+
      "It is filled with barrels, old sail cloth, coils of rope, "+
      "and crates.  The schooner rocks gently "+
      "from the small waves that lap against its hull.  "+
      "A wooden ladder leads up to the craft's deck."
    );
    add_exit("/d/khojem/port/room/ship2","up");
    set_items(([
     ({ "deck" }) :
        "The underside of the teakwood deck is used to hang hammocks.",
     ({ "barrels", "sail cloth", "cloth", "rope", "crates" }) :
        "These items are worthless and the sailors have discarded them here.",
     ({ "hull" }) :
        "The hull is leaking slowing at a few points.",
     ({ "ship","schooner" }) :
        "Well, it certainly is here.",
     ({ "ladder", "wooden ladder" }) :
        "A steep wooden ladder leads up to the main deck.",
    ]));
    set_smell("default", "Huh!  It smells like something died down here.");
    set_listen("default", "You hear the small waves lap against the side of "+
      "the hull.");
}
