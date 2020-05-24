//      Wizard:  Khojem
//      Practice Yard
//      md_yard.c

#include <std.h>

inherit ROOM;

void reset() {
   ::reset();
   new("/d/khojem/zone/mon/sentry")->move(this_object());
   new("/d/khojem/zone/mon/sentry")->move(this_object());
   new("/d/khojem/zone/mon/sentry")->move(this_object());
   new("/d/khojem/zone/mon/sentry")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Practice Yard");
    set("long", "This is the practice yard for the towns guards. "+
      "Many practice dummies made of straw are here for the guards "+
      "to work on.  Walls surround this small yard."
   );
   add_exit("md_gdbrks","south");
      set_items(([
      ({ "dirt", "ground", "floor" }) : 
        "The floor is a slippery, hard mud from constant use.",
      ({ "dummy", "dummies", "practice dummies" }) : 
        "The dummies have sustained many damages due to constant use.  "+
        "They are made of straw and the cloth that binds them is torn.",
      ({ "wall", "walls" }) :
        "The wall is poorly constucted and water is leaking in."
      ]));
   set_smell("default", "A horrible, rotten smell permeates the air.");
   set_listen("default", "All around you are the sounds of slow dripping water.");
}
