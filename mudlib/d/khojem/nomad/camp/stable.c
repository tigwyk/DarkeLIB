//      Wizard:  Khojem
//      Stable
//      stable.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
   ::init();
   add_action("do_climb","climb");
}

void reset() {
   ::reset();
  if(!present("camel")) {
    new("/d/khojem/nomad/mon/camel")->move(this_object());
    new("/d/khojem/nomad/mon/camel")->move(this_object());
    new("/d/khojem/nomad/mon/camel")->move(this_object());
    new("/d/khojem/nomad/mon/camel")->move(this_object());
    new("/d/khojem/nomad/mon/camel")->move(this_object());
  }
}

void create() {
  string desc;
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_property("night light",1);
  set("short", "nomad stables");
  desc = "This is where the nomads stable their camels.  The dung "+
    "is deep here and the huge sand flies swarm and bite you "
    "repeatedly.  The stable is nothing much.  It is behind and "
    "away from the other tents.  A few ropes tether the camels "
    "to a nearby palm.";
  set("day long","The palm trees grow less dense here and offer "
    "little protect from the hot sun.  "+desc
  );
  set("night long","The night air chills your bones and robs "
    "you of body heat.  "+desc
  );
  add_exit("/d/khojem/nomad/camp/center","northeast");
  set_items(([
    ({ "stable" , "stables" }) :
      "It is an unorganized affair.  It is a small clearing in "
      "the palm trees.  A series of ropes between the animals "
      "tether them to a lone palm tree.",
    ({ "palm tree","tree", "palm" }) :
      "A lone palm tree is here.  The desert winds have bent the "
      "palm's truck so it no longer grows straight out of the sand "
      "and upwards to the sky.",
    ({ "dung" }) :  "Oh!  It looks so revolting!",
    ({ "rope", "ropes" }) :  
      "The series of cheap ropes link the animals together.  The "
      "rope is constructed of desert grass."  
]));
  set_smell("default", "The smell of fresh camel manure is "
    "overpowering.");
  set_listen("default", "The camp is noisy.  People shouting and "
    "dogs barking.");
  set_search("dung", (: call_other, this_object(),"do_search" :) );
  set_search("shit", (: call_other, this_object(),"do_search" :) );
}

int do_climb(string str){
  if(str == "tree" || str == "palm" || str == "palm tree") {
    write("With considerable effort you manage to climb the palm "
      "tree.\n");
    message("info",this_player()->query_cap_name()+" struggles to the "
      "top of the palm tree.\n","/d/khojem/nomad/camp/tree",
      this_player());
    find_object_or_load("/d/khojem/nomad/camp/tree");
    this_player()->move_player("/d/khojem/nomad/camp/tree");
    return 1;
  }
  return 0;
}

void do_search() {
  message("info",this_player()->query_cap_name()+" appears to be "
    "searching the huge piles of dung on the ground.  "
    +this_player()->query_cap_name()+"'s arms are covered with "
    "camel shit!  Repulsed, "+this_player()->query_cap_name()
    +" walks over to the sand and scrubs the dung off with the "
    "coarse sand.\n",this_object(),this_player());
  message("info","You dip your arms up to the elbows in the large "
    "piles of camel dung.  You find more shit and now it is all "
    "over your arms.  Yuck! You step off towards the sand and "
    "start scubbing your arms with the sand.\n",this_player());
  return;
}
