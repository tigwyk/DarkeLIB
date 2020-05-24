//      Wizard:  Khojem
//      Nomad Entry
//      entry.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","west");
    }
}

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
      "much of the road.  Rolling sand dunes can be seen on both sides "+
      "of the road.\n"
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing on a desolate, desert road.  The road stretches "+
      "far and extends to the horizon.  The wind-swept sand covers "+
      "much of the road.  Rolling sand dunes can be seen on both sides "+
      "of the road.\n"
    );
    add_exit("/d/khojem/nomad/room/r1","east");
    add_exit("/d/damned/virtual/room_50_25.world","out");
    set_items(([
        "road" : "Coarse gravel stones allow wheeled carts to travel this "+
          "sandy terrain.  But, you see it has fallen into disrepair.\n",
     ({ "sand","sand dunes","dunes" }) :
        "The sand dunes are low and allow you to see off into the distance.",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
    new("/d/khojem/nomad/obj/mono1")->move(this_object());
}
