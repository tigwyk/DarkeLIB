//      Wizard:  Khojem
//      Guard Post
//      md_gdpost.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   new("/d/khojem/zone/mon/sgt_guard")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Guard Post");
    set("long", "This is the Guard's Post.  Here travellers and "+
      "merchants must be checked for illegal goods.  The room is "+
      "very small and surrounded by masonry walls."
   );
   add_exit("md_gdroom","west");
      set_items(([
      ({ "dirt", "ground", "floor" }) : 
        "The floor is a slippery, hard mud from constant use.",
      ({ "wall", "walls" }) :
        "The wall is poorly constucted and water is leaking in."
      ]));
   set_smell("default", "A horrible, rotten smell permeates the air.");
   set_listen("default", "All around you are the sounds of slow dripping water.");
}
