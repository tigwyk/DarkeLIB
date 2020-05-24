//      Wizard:  Khojem
//      MD-General Store - Storage Room
//      md_gshop_storage.c

#include <std.h>

inherit ROOM;

 void reset() {
   ::reset();
   new("/d/khojem/kho_sword")->move(this_object());
    }


void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("storage room",1);
    set("short", "short");
    set("long", "Morty's storage room"
  );
    set_exits( ([]) );
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "All around you are the sounds of slow dripping water.");
}

