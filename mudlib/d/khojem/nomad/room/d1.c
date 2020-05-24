//      Wizard:  Khojem
//      desert 1
//      d1.c

#include <std.h>

inherit ROOM;

int check_mobs();

int search_flag;

int clean_up() {
  if(check_mobs()<3) return 1;
  return ::clean_up();
}

void reset() {
    ::reset();
    search_flag=0;
   if(check_mobs()<1) {
      new("/d/khojem/nomad/mon/nutnux")->move(this_object());
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
      "Hmm... you have lost the road and now you are lost, too.  "+
      "Your feet and legs sink deep into the sand.  Every step is "+
      "a struggle as you wade through the hot sand.  Sand dunes are "+
      "all around you."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "Hmm... you have lost the road and now you are lost, too.  "+
      "Your feet and legs sink deep into the sand.  Every step is "+
      "a struggle as you wade through the cold sand.  Sand dunes are "+
      "all around you."
    );
    add_exit("/d/khojem/nomad/room/d2","north");
    add_exit("/d/khojem/nomad/room/d3","northeast");
    add_exit("/d/khojem/nomad/room/d4","east");
    add_exit("/d/khojem/nomad/room/d5","southeast");
    add_exit("/d/khojem/nomad/room/d6","south");
    add_exit("/d/khojem/nomad/room/d7","southwest");
    add_exit("/d/khojem/nomad/room/d8","west");
    add_exit("/d/khojem/nomad/room/d9","northwest");
    set_search("sand",(: call_other, this_object(),"do_search" :));
    set_items(([
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
}

void do_search() {
  int skill;
  object ob;
  string zplayer;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "about the sand.\n");
  skill=((int)this_player()->query_skill("perception"))-20;
  if(random(100)<skill && search_flag==0) {
    search_flag=1;
    write("Your search is successful.\nYou discover a sand devil!");
    zplayer=(this_player()->query_cap_name());
    ob=new("/d/khojem/nomad/mon/sand_devil");
    ob->move(this_object());
    ob->kill_ob(this_player(),0);
  }
  else
    write("Your search yields nothing.");
  return;
}

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/d/khojem/nomad/mon/nutnux")  
    return 1;                                        
  return 0;
}

