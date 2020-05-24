//      Wizard:  Khojem
//      rope bridge
//      rb.c

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
      "You are standing on a rope-bridge that spans a deep, dark ravine.  "+
      "The ravine is too deep and narrow to see down to its bottom.  "+
      "In the distance you can see sand dunes in all directions.  To the "+
      "north you can see where the rope-bridge anchors to the far side of "+
      "the ravine.  Also, towards the far north, you can make out a stone "+
      "structure of some kind."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing on a rope-bridge that spans a deep, dark ravine.  "+
      "The ravine is too deep and narrow to see down to its bottom.  "+
      "To the north and south you can just make out where the rope-bridge "+
      "anchors to the both sides of the ravine."
    );
    add_exit("/d/khojem/nomad/room/rv10","north");
    add_exit("/d/khojem/nomad/room/rv1","south");
    add_exit("/d/khojem/nomad/room/rv2","down");
    add_invis_exit("down");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
     ({ "rocks", "rocky precipice", "precipice", "rock" }) :
        "The rocks are razor-sharp.  Climbing down is impossible.  You would fall "+
        "to your death.",
     ({ "ravine" }) :
        "The steep, jagged rocks extend downward into the dark, abyss below.",
     ({ "rope-bridge", "rope bridge", "bridge" }) :
        "The bridge is poorly constructed of rope-like vines.  Due to "+
        "years of exposure to the elements it has severely decayed.",
     ({ "structure","stone structure" }) :
        "The structure is too far away to make out any of its details."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
}

int go_down(){
  if(this_player()->query_flying()){
    write("You fly down into the deep ravine a ways.\n");
    tell_room("/d/khojem/nomad/room/rv2",
      this_player()->query_cap_name()+" gracefully flys down from above.\n");
    return 1;
    }
  write("Huh?  That would be suicide!\n");
  return 0;
}
