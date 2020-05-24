//      Wizard:  Khojem
//      MD-General Store
//      md_gshop.c

#include <std.h>

inherit ROOM;


// void reset() {
//    ::reset();
//    if (!present("morty")) {
//       new("/d/khojem/zone/mon/morty")->move(this_object());
//    }
// }


void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Morty's General Store");
    set("long", "Morty appears to run a brisk business.  "+
      "Like all citizens of this town he dislikes foreigners but "+
      "Morty is willing to overlook his dislikes in exchanged for "+
      "a sizable profit."
  );
    add_exit("md_swmksq","north");
    add_exit("md_gshop_storage","south");
    add_invis_exit("south");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

