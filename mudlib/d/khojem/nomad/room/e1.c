//      Wizard:  Khojem
//      east cardinal exit
//      e1.c

#include <std.h>

inherit ROOM;

int check_mobs();

int no_exit() { return 1;}

void reset() {
  int m = check_mobs();

    ::reset();
    if(m<6) {
      new("/d/khojem/nomad/mon/sand_devil")->move(this_object());
    }
    if(m<3) new("/d/khojem/nomad/mon/sand_devil")->move(this_object());
}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","east");
    }
}


void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 0);
    set_property("night light",1);
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
    add_exit("/d/damned/virtual/room_50_25.world","east");
    add_exit("/d/khojem/nomad/room/d11","west");
    add_exit("/d/khojem/nomad/room/oasis","southwest");
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
  if(base_name(mob) == "/d/khojem/nomad/mon/sand_devil")  
    return 1;                                        
  return 0;
} 
