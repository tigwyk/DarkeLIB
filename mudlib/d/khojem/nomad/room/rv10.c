//      Wizard:  Khojem
//      rope bridge
//      rv1.c

#include <std.h>

inherit ROOM;

void init() {
    ::init();
}

void reset() {
    ::reset();
    if(!present("harghuul")){
      new("/d/khojem/nomad/mon/harghuul")->move(this_object());
    }
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 0);
    set_property("night light",1);
    set("short", "Near a deep ravine");
    set("day long",
      "The bright, hot sun burns down on the back of your neck.  "+
      "You are standing on the north side of a ravine.  A rope-bridge is "+
      "anchored at this side and spans a deep, dark ravine towards the south.  "+
      "The ravine is too deep and narrow to see down to its bottom.  "+
      "Towards the north, you see the rubble of a stone structure of some kind.  "+
      "In the distance you can see sand dunes in all directions."
   );
    set("night long",
      "The night air chills your bones and robs you of body heat.  "+
      "You are standing on the north side of a ravine. A rope-bridge is "+
      "anchored at this side and spans a deep, dark ravine towards the south.  "+
      "The ravine is too deep and narrow to see down to its bottom.  "
    );
    add_exit("/d/khojem/nomad/room/temple","north");
    add_exit("/d/khojem/nomad/room/rb","south");
    set_pre_exit_functions(({"north"}),({"go_north"}));
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
     ({ "structure","rubble","stone structure" }) :
        "A dark, stone building stands crumbling to the north."
    ]));
    set_smell("default", "The dry, arid air burns your nose.");
    set_listen("default", "The silence is interrupted only by your footsteps.");
}

int go_north() {
  if(present("harghuul")) {
    write("Harghuul cackles and blocks your exit.\n");
    return 0;
  }
  else return 1;
}
