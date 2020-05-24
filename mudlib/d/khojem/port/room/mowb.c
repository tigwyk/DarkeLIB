//      Wizard:  Khojem
//      mowb.c

#include <std.h>
inherit ROOM;

void reset() {
    ::reset();
  if(!present("sailor")) {
    new("/d/khojem/port/mon/boatswain")->move(this_object());
    new("/d/khojem/port/mon/captain")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "Cabin of a Man-o-War Fighting Vessel");
    set("long","This is the captain's cabin of a Man-o-War Fighting Vessel.  "+
      "The deck is directly south beyond an open doorway.  A window can be "+
      "seen to the north.  A bunk is to the east and a small desk dominates "+
      "the room."
    );
    add_exit("/d/khojem/port/room/mow","south");
    set_items(([
     ({ "doorway", "deck" }) :
        "A doorway leads south to the teakwood deck of the ship.",
     ({ "cabin" }) :
        "Other than the desk being filled with papers and charts the "+
        "cabin appears to be orderly.",
     ({ "papers" }) :
        "On the rosewood desk are a number of official looking papers.  "+
        "One looks like an order.",
     ({ "order" }) :
        "The order reads:\nBy authority of the Earl of Vo'Sangor you are "+
        "commanded rid the area of pirates.  You are to use whatever means "+
        "are at your disposal.\n         Signed, Earl of Vo'Sangor\n",
     ({ "desk" }) :
        "The rosewood desk is filled with papers and charts.",
     ({ "charts" }) :
        "The charts consists of navigational charts of the harbor of "+
        "Vo'Sangor and the seas in the vicinity of its merchant channel.",
     ({ "ship","vessel","man-o-war" }) :
        "The man-o-war is a fine fighting ship.  When sails are set and "+
        "with a good wind it will run very fast.",
     ({ "harbor", "waves", "water", "window" }) :
        "Through the ship's aft window you can see the harbor and the small "+
        "waves splashing up against the pilings of the docks.",
     ({ "street","wharf","dock" }) :
        "The docks can be seen through the aft window."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The sound of lapping water and seagulls.");
}

