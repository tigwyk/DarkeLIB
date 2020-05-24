//      Wizard:  Khojem
//      ravine 4
//      rv4.c

#include <std.h>

inherit ROOM;

void reset() {
    ::reset();
    if(!present("hyena")){
      new("/d/khojem/nomad/mon/hyena")->move(this_object());
      new("/d/khojem/nomad/mon/hyena")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("night light",0);
    set("short", "A deep ravine");
    set("day long",
      "You are standing at the base of the ravine.  The walls of the "+
      "ravine are narrow and frequently its sharp rocks protrude forcing "+
      "you to avoid them as you walk.  The ravine's base is very dark and "+
      "you can only see a few feet ahead.  High above you see a bright streak "+
      "of light against the darkness.  "
   );
    set("night long",
      "You are standing at the base of the ravine.  The walls of the "+
      "ravine are narrow and frequently its sharp rocks protrude forcing "+
      "you to avoid them as you walk.  The ravine's base is very dark and "+
      "you can only see a few feet ahead.  "
    );
    add_exit("/d/khojem/nomad/room/rv3","west");
    set_items(([
     ({ "rocks", "rock" }) :
        "The rocks are razor-sharp.  Climbing down or up is your only "+
        "choice.", 
     ({ "ravine" }) :
        "The steep, jagged rocks line the walls of this narrow ravine.  "+
        "The ravine's floor is coated with a soft, layer of fine sand."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "You here animals closeby and approaching you.");
}
