//      Wizard:  Khojem
//      mow.c

#include <std.h>
inherit ROOM;

void reset() {
    ::reset();
  if(!present("sailor")) {
    new("/d/khojem/port/mon/sailor2")->move(this_object());
    new("/d/khojem/port/mon/sailor2")->move(this_object());
    new("/d/khojem/port/mon/sailor2")->move(this_object());
    new("/d/khojem/port/mon/marine")->move(this_object());
    new("/d/khojem/port/mon/marine")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "Deck of a Man-o-War Fighting Vessel");
    set("long","This is the deck of a Man-o-War Fighting Vessel.  The ship is "+
      "berthed at Vo'Sangor's dock.  The dock is directly west and a wood "+
      "plank provides access to the wharf.  The ship has high gunwhales to "+
      "protect fighters while they throw spears.  The breeze causes the "+
      "slipped sails to flap the riggings against the masts and yardarms.  "+
      "A wooden ladder descends down into the hull of the craft and an open "+
      "doorway leads northward."
    );
    add_exit("/d/khojem/port/room/s11","plank");
    add_exit("/d/khojem/port/room/mowa","down");
    add_exit("/d/khojem/port/room/mowb","north");
    set_items(([
     ({ "gunwhales" }) :
        "The high gunwhales surround the deck and provide protection when "+
        "an enemy ship is close abeam.",
     ({ "doorway", "cabin" }) :
        "A doorway leads aft to a darken cabin.",
     ({ "deck" }) :
        "The teakwood deck is well maintained due to the sailor's constant "+
        "deck swabbing.",
     ({ "sails", "sail", "riggings", "rigging", "cleats", "cleat" }) :
        "The sails are wrapped around the yardarms and tied with rope.  "+
        "The brass rigging and cleats are highly polished.",
     ({ "yardarms", "mast", "masts", "yardarm" }) :
        "The masts and yardarms are constructed of teakwood.",
     ({ "ship","vessel","man-o-war" }) :
        "The man-o-war is a fine fighting ship.  When sails are set and "+
        "with a good wind it will run very fast.",
     ({ "harbor", "waves", "water" }) :
        "The harbor lies to the east.",
     ({ "ladder", "wooden ladder" }) :
        "A steep wooden ladder leads down to the quarters below deck.",
     ({ "plank" }) :
        "A weather-beaten, thick wooden plank leads west to the dock.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","wharf street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water.  "+
        "The man-o-war is docked up against it."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The sound of lapping water and seagulls.");
}

