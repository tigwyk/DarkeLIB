//      Wizard:  Khojem
//      This is the deck of the pirate ship
//      ship2.c

#include <std.h>
inherit VAULT;

void reset() {
    ::reset();
  if(!present("pirate")) {
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
    new("/d/khojem/port/mon/pirate1")->move(this_object());
  }
}    

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "Deck of a Pirate Ship");
    set("long","You are standing on the deck of a pirate vessel berthed at "+
      "the wharf in Vo'Sangor.  The wharf is to the north and a hatch "+
      "provides access to the wharf.  The pirate schooner rocks gently "+
      "from the small waves that lap against its hull.  The breeze causes the "+
      "slipped sails to flap the riggings against the spars and mast.  "+
      "A wooden ladder descends "+
      "down into the hull of the craft."
    );
    add_exit("/d/khojem/port/room/s25","north");
    add_exit("/d/khojem/port/room/ship2a","down");
    add_invis_exit("north");
    set_door("hatch","/d/khojem/port/room/s25","north",0);
    set_func("hatch","open","do_open");
    set_func("hatch","close","do_close");
    set_items(([
     ({ "hatch" }) : 
        (: call_other, this_object(), "look_at_door" :),
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

void look_at_door() {
  if(query_open("hatch")) 
    write("The hatch is wide open.\n");
  else 
    write("The hatch is closed.\n");
  say(this_player()->query_cap_name()+" examines a hatch.\n");
}

int do_open() {
  remove_invis_exit("north");
  "/d/khojem/port/room/s25"->remove_invis_exit("south");
  return 1;
}
 
int do_close() {
  add_invis_exit("north");
  "/d/khojem/port/room/s25"->add_invis_exit("south");
  return 1;
}

