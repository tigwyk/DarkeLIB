//      Wizard:  Khojem
//      Mage's Hut
//      mage_hut.c

#include <std.h>

inherit ROOM;

int rap_count, trap_open;

void init() {
    ::init();
    add_action("do_rap","rap");
    rap_count = 0;
    trap_open = 0;
}

void reset() {
    ::reset();
   if(!present("mage"))
      new("/d/khojem/new/mon/mage")->move(this_object());
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "   0\n   | \n   @   \n     \n    \nA small, domed hut");
    set("long", "This is a small, one-room hut with a domed, thatched roof.  "+
      "Other than some bedding in the corner the room is void of any "+
      "furnishings.  The planked wood floor is sweeped clean.\n   0\n   | \n   @   \n     \n    \n"  
    );
    add_exit("plat4","north");
    set_items(([
        "hut" :  "The domed hut is clean and well maintained.",
     ({ "thatched roof", "roof", "domed" }) :
        "The roof is woven with leaves and vines from the forest.  "+
        "It is dome-shaped and the roof curves down a serves as "+
        "the hut's walls as it nears the floor.",
     ]));
    set_smell("default", "The air is chill and void of smell.");
}

int do_rap(string str) {
  int f1, f2;
  string  p1;
  if (!str) return 0;
  f1 = sscanf(str,"%*s floor",p1);
  f2 = sscanf(str,"%*s fist",p1);
  if(f1>0 && f2>0) {
    rap_count++;
    write("You kneel and rap on the wooden floor with a closed fist.\n");
    tell_room(this_object(),this_player()->query_cap_name()+" kneels "+
      "to the floor and soundly raps the wooden floor with a fist.\n",
      this_player());
    if(rap_count>2) {
      tell_room(this_object(),"With a moan the floor planks shift and "+
        "a small trapdoor opens by some unseen magical force.  A wooden "+
        "ladder leads down through the trapdoor.");
      trap_open = 1;
      add_exit("trap_door","trapdoor");
      set_pre_exit_functions(({"trapdoor"}),({"go_trap"}));
      set_items(([
          "trapdoor" : "The trapdoor is open and leads down into darkness.",
          "ladder"  :  "A simple wooden ladder leads downwards.",
          "hut" :  "The domed hut is clean and well maintained.",
       ({ "thatched roof", "roof", "domed" }) :
          "The roof is woven with leaves and vines from the forest.  "+
          "It is dome-shaped and the roof curves down a serves as "+
          "the hut's walls as it nears the floor.",
       ]));
      call_out("close_trap",120);
      return 1;
    }
    return 1;
  }
  else return 0;
}

void close_trap() {
  tell_room(this_object(),"With a moan the floor planks shift and "+
    "the trapdoor is sealed shut.\n");
  remove_exit("trapdoor");
  trap_open=0;
  rap_count=0;
  return;
}

int go_trap() {
  if(present("mage")) {
    write("The wood-elf mage steps before you and blocks your exit.\n");
    return 0;
  }
  else return 1;
}


