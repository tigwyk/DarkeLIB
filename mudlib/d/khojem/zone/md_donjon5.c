//      Wizard:  Khojem
//      Donjon Room 5
//      md_donjon5.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   if (!present("plguard2")) {
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
   new("/d/khojem/zone/mon/plguard2")->move(this_object());
   }
}

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Donjon Summit");
    set("long", 
      "Your climb leads you to the top of the Donjon."+
      "Around you are the battlements.  From here you could probably "+
      "have a good vantage point over the city below, but you cannot "+
      "see far due to the darkness.  Stairs lead down into the Donjon."
   );
    set_items(([
      ({ "stairs","stair" }) :
        "A series of stone masonery steps lead up and down.",
        "battlements" :  "A series of masonry vantage points to "+
        "protect defenders of the city from warriors below."
       ]));
    add_exit("md_donjon4","down");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "The wind is howling all around you.");
}
