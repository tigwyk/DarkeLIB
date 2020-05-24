//      Wizard:  Khojem
//      ravine 1
//      rv1.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","north");
      add_action("no_exit","down");
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
    set("short", "Near a deep ravine");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You are standing on a rocky precipice above a steep ravine.  "+
      "A rope-bridge spans the ravine to the north.  "+
      "In the distance you can see sand dunes and a few scattered tracks "+
      "that lead out to the dunes."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing on a rocky precipice above a steep ravine.  "+
      "A rope-bridge extends to the north above the ravine.  You can't "+
      "see where it anchors on the other side of the ravine.  "+
      "In the distance you can see sand dunes and a few scattered tracks "+
      "that lead out to the dunes."

    );
    add_exit("/d/khojem/nomad/room/n1","northeast");
    add_exit("/d/khojem/nomad/room/d3","east");
    add_exit("/d/khojem/nomad/room/d1","southeast");
    add_exit("/d/khojem/nomad/room/d9","southeast");
    add_exit("/d/khojem/nomad/room/rb","north");
    add_exit("/d/khojem/nomad/room/rv2","down");
    add_invis_exit("down");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
     ({ "track","tracks" }) :
        "The tracks are footprints in the sand that have not been swept away.",
     ({ "sand","sand dunes","dunes" }) :
        "The high sand dunes block your view to the horizon.\n",
     ({ "rocks", "rocky precipice", "precipice", "rock" }) :
        "The rocks are razor-sharp.  Climbing down appears impossible.  If you "+
        "didn't fall the rocks would certainly cut you severely during the climb.",
     ({ "ravine" }) :
        "The steep, jagged rocks extend downward into the dark, abyss below.",
     ({ "rope-bridge", "rope bridge", "bridge" }) :
        "The bridge is poorly constructed of rope-like vines.  Due to "+
        "years of exposure to the elements it has severely decayed."
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
  write("Maybe this wasn't such a good idea?  You can climb down without "+
    "falling, but the rocks seriously cut and gash you.\n");
  say(this_player()->query_cap_name()+" foolishly attempts to climb down "+
    "into the darkness of the ravine.\n");
  this_player()->add_hp(-(random(50)+50));
  return 1;
}

