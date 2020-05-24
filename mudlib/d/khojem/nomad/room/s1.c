//      Wizard:  Khojem
//      south cardinal exit
//      s1.c

#include <std.h>

inherit ROOM;

int search_count;
object ob;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","south");
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
    add_exit("/d/damned/virtual/room_21_12.world","south");
    add_exit("/d/khojem/nomad/room/d6","northwest");
    add_exit("/d/khojem/nomad/room/oasis","northeast");
    add_exit("/d/khojem/nomad/room/d10","north");
    set_items(([
     ({ "track","tracks" }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
    set_search("sand",(: call_other, this_object(),"do_search" :));
    search_count=0;
}


void do_search() {
  int skill;
  string zplayer;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "around in the sand.\n");
  skill=((int)this_player()->query_skill("perception"))-20;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
      "You discovered a sleeping sandman.\n"+
      "He disliked being awakened by your search!\n");
    zplayer=(this_player()->query_cap_name());
    ob=new("/d/khojem/nomad/mon/sand_man");
    ob->move(this_object());
    ob->kill_ob(this_player(),0);
  }
  else
    write("Your search yields nothing.");
  return;
}


