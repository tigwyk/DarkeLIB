//      Wizard:  Khojem
//      desert 3
//      d3.c

#include <std.h>

inherit ROOM;

int check_mobs();

void reset() {
    ::reset();
    if(check_mobs()<1 && random(4)) {
      new("/d/khojem/nomad/mon/nomad_scout")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light",1);
    set_property("indoors", 0);
    set("short", "The scorching desert");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You notice a few scattered tracks in the sand that lead out.  "+
      "Your feet and legs sink deep into the sand.  Every step is "+
      "a struggle as you wade through the hot sand.  Sand dunes are "+
      "all around you."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You notice a few scattered tracks in the sand that lead out.  "+
      "Your feet and legs sink deep into the sand.  Every step is "+
      "a struggle as you wade through the cold sand.  Sand dunes are "+
      "all around you."
    );
    add_exit("/d/khojem/nomad/room/d2","north");
    add_exit("/d/khojem/nomad/room/n1","northeast");
    add_exit("/d/khojem/nomad/room/d4","east");
    add_exit("/d/khojem/nomad/room/rv1","west");
    add_exit("/d/khojem/nomad/room/d11","southeast");
    add_exit("/d/khojem/nomad/room/d1","southwest");
    set_items(([
     ({ "track","tracks" }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
}

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/nomad_scout")  
    return 1;                                        
  return 0;
}                                      

