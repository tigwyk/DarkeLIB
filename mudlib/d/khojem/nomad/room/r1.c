//      Wizard:  Khojem
//      desert road 1
//      r1.c

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
    set("short", "The scorching desert");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You are standing on a desolate, desert road.  The road stretches "+
      "far and extends to the horizon.  The wind-swept sand covers "+
      "much of the road.  The sand starts to cover your feet and travel "+
      "is getting more difficult.  Rolling sand dunes can be seen on both sides "+
      "of the road.\n"
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing on a desolate, desert road.  The road stretches "+
      "far and extends to the horizon.  The wind-swept sand covers "+
      "much of the road.  The sand starts to cover your feet and travel "+
      "is getting more difficult.  Rolling sand dunes can be seen on both sides "+
      "of the road.\n"
    );
    add_exit("/d/khojem/nomad/room/entry","west");
    add_exit("/d/khojem/nomad/room/r2","east");
    set_items(([
        "road" : "Coarse gravel stones allow wheeled carts to travel this "+
          "sandy terrain.  But, you see it has fallen into disrepair.\n",
     ({ "sand","sand dunes","dunes" }) :
        "The sand dunes are low and allow you to see off into the distance.",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
}
