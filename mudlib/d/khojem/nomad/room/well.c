//      Wizard:  Khojem
//      well of darke souls
//      well.c

#include <std.h>

inherit ROOM;

void reset() {
    ::reset();
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "Near a well in the scortching desert");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You notice a set of tracks in the sand that lead southwest.  "+
      "Before you is an old well constructed of baked clay.  The well "+
      "is crumbling and decayed.  Heard through the wells opening are "+
      "wails and moans from some creature or creatures not of this world.  "+
      "The sound chills you to the bone even in this heat.  "+
      "Your feet and legs sink deep into the sand.  Sand dunes are "+
      "all around you."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You notice a set of tracks in the sand that lead southwest.  "+
      "Before you is an old well constructed of baked clay.  The well "+
      "is crumbling and decayed.  Heard through the wells opening are "+
      "wails and moans from some creature or creatures not of this world.  "+
      "The sounds make the night air seem more chill.  "+
      "Your feet and legs sink deep into the sand.  Sand dunes are "+
      "all around you."
    );
    add_exit("/d/khojem/nomad/room/d11","southwest");
    set_items(([
     ({ "track"  }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
     ({ "well" }) :
        "With the oasis nearby someone must have thought to construct this "+
        "well to provide an uninterrupted water supply to the area.  Now, "+
        "due to years of neglect the well has crumbled and decayed."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The eerie sound of wavering wails fill the air.");
    new("/d/khojem/nomad/obj/mono4")->move(this_object());
}
