//      Wizard:  Khojem
//      mowa.c

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
    set_property("light", 2);
    set_property("night light",2);
    set_property("indoors", 1);
    set("short", "Below Deck of a Man-o-War Fighting Vessel");
    set("long","This is the below deck of a Man-o-War Fighting Vessel.  "+
      "The waves cause the ship to rock occasionally.  This area appears "+
      "to be used to barracks the crew of the ship.  "+
      "A wooden ladder leads up to the ship's deck."
    );
    add_exit("/d/khojem/port/room/mow","up");
    set_items(([
     ({ "sails", "sail", "riggings", "rigging", "cleats", "cleat" }) :
        "The sails are wrapped around the yardarms and tied with rope.  "+
        "The brass rigging and cleats are highly polished.",
     ({ "yardarms", "mast", "masts", "yardarm" }) :
        "The masts and yardarms are constructed of teakwood.",
     ({ "ship","vessel","man-o-war" }) :
        "The man-o-war is a fine fighting ship.  When sails are set and "+
        "with a good wind it will run very fast.",
     ({ "ladder", "wooden ladder" }) :
        "A steep wooden ladder leads down to the quarters below deck.",
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The sound of lapping water and seagulls.");
}
