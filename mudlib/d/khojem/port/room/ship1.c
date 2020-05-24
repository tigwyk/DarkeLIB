//      Wizard:  Khojem
//      ship1.c

#include <std.h>
inherit ROOM;

void reset() {
    ::reset();
  if(!present("sailor")) {
    new("/d/khojem/port/mon/sailor1")->move(this_object());
    new("/d/khojem/port/mon/sailor1")->move(this_object());
    new("/d/khojem/port/mon/sailor1")->move(this_object());
    new("/d/khojem/port/mon/sailor1")->move(this_object());
    new("/d/khojem/port/mon/sailor1")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "Deck of a Schooner");
    set("long","You are standing on the deck of a schooner berthed at "+
      "the wharf in Vo'Sangor.  The wharf is directly north and a wood "+
      "plank provides access to the wharf.  The schooner rocks gently "+
      "from the small waves that lap against its hull.  The breeze causes the "+
      "slipped sails to flap the riggings against the spars and mast.  "+
      "A wooden ladder descends "+
      "down into the hull of the craft."
    );
    add_exit("/d/khojem/port/room/s24","plank");
    add_exit("/d/khojem/port/room/ship1a","down");
    set_items(([
     ({ "deck" }) :
        "The teakwood deck has seen years of exposure to the sea's elements.  "+
        "Saltwater and salt air has taken its toil on the worn deck.",
     ({ "sails", "sail", "riggings", "rigging" }) :
        "The sails are heavily patched and grimy.  The brass rigging is "+
        "tarnished.",
     ({ "spars", "mast", "masts" }) :
        "The masts and spars are constructed of teakwood.",
     ({ "ship","schooner" }) :
        "The schooner is a worn ship, but appear still seaworthy.  "+
        "It has foremast and mainmast stepped near amidships.",
     ({ "harbor", "waves", "water" }) :
        "The harbor extends south to the horizon.",
     ({ "ladder", "wooden ladder" }) :
        "A steep wooden ladder leads down to the quarters below deck.",
     ({ "plank" }) :
        "A weather-beaten, thick wooden plank leads north to the dock.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","wharf street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water.  "+
        "The schooner is docked up against it."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "The sound of lapping water and seagulls.");
}
