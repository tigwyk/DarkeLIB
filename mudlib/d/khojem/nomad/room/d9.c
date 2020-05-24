//      Wizard:  Khojem
//      desert 9
//      d9.c

#include <std.h>

inherit ROOM;

int check_mobs();

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("read_sign","read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
    }
    else
      add_action("read_sign","read");
}

int clean_up() {
  if(check_mobs()<6) return 1;
  return ::clean_up();
}

void reset() {
    ::reset();
    if(check_mobs()<6) {
      new("/d/khojem/nomad/mon/sidewinder")->move(this_object());
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
    add_exit("/d/khojem/nomad/room/rv1","northwest");
    add_exit("/d/khojem/nomad/room/d2","east");
    add_exit("/d/khojem/nomad/room/d1","southeast");
    add_exit("/d/khojem/nomad/room/d8","south");
    add_exit("/d/khojem/nomad/room/sp1","north");
    add_pre_exit_function("north","go_north");
    set_items(([
        "sign" : "The sign points to the north.\n"+
          "Maybe you should try to read it?",
     ({ "track","tracks" }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
    new("/d/khojem/nomad/obj/sign")->move(this_object());
}

int go_north(){
  write("\nYou walk a few yards and suddenly the sand is shifting all around you.  "+
    "Within seconds you are too deep in the sand to escape.  You struggle but the "+
    "sand yields to your efforts and you lack leverage to escape from the sand "+
    "marsh.\n\nAfter a short fall you land on a soft layer of sand.\n"
  );
  tell_room("/d/khojem/nomad/room/sp1",
    this_player()->query_cap_name()+" falls from above and "+
     "lands flat on his ass beside you just beside you.\n");
  return 1;
}

int read_sign(string str){
  if(str != "sign") return 0;
  write("The wooden, sun-bleached sign reads:\n\n   Danger!  Sand Marsh\n\n"+
    "A blood-red scrawl in the lower corner reads:   Spiders\n\n"+
    "The sign points to the north.\n");
  return 1;
}

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/siderwinder")  
    return 1;                                        
  return 0;
}                                      

