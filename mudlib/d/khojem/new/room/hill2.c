//      Wizard:  Khojem
//      hill2
//      hill2.c

#include <std.h>

inherit ROOM;

void init() {
  ::init();
  add_action("get_rope","get");
  add_action("untie_rope","untie");
}

void reset() {
	::reset();
    if (!present("half-orc warrior" , this_object()) ) {
      if(random(2)) {
        new("/d/khojem/new/mon/orc_warrior2")->move(this_object());
	  }
	}
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   \n     \n0--@   \n   d \n   \nA steep, hill path");
    set("long", "The steep trail ends here on a small clearing atop "+
      "the hill.  The forest bordering the clearing appears dense and "+
      "impassible.  In the center of the small clearing is a hole.\n   \n     \n0--@   \n   d \n   \n"
    );
    add_exit("/d/khojem/new/room/hole","down");
    add_exit("hill1","west");
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_items(([
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "trail","path" }) :
        "The trail below is steep and worn from frequent use.",
        "hole" : "The hole is roughly four feet in diameter... enough "+
          "for you to easily pass through.  The area around the hole "+
          "appears trampled from constant use.  You see some very large "+
          "footprints nearby.  Descending into the hole is a rope.",
     ({ "footprints", "footprint" }) :
        "Whoever made these footprints was very large and barefoot.  "+
        "The person was humanoid and stood erect on two feet.",
        "rope" : "The rope is a thick, sturdy rope.  One end is tied to "+
          "a large rock.  The other descends freely into the darkness "+
          "of the hole.",
        "rock" : "The rope is securely tied to a large rock firmly "+
          "embedded in the ground."
    ]));
    set_smell("default", "The smell of growth and decaying wood is "+
      "everywhere.");
    set_listen("default", "The woods are quiet and still.");
}

int get_rope(string str){
  if (!str){return 0;}
  if (str !="rope") {return 0;}
  write("The rope is too tightly tied for you to get.");
  return 1;
}

int untie_rope(string str){
  if (!str){return 0;}
  if (str !="rope") {return 0;}
  write("After considerable effort you manage to do nothing.");
  return 1;
}

int go_down(){
  write("You grab the rope and start your descent.  "+
    "You struggle for a few minutes as you descend the rope.  "+
    "Suddenly, you realize the rope is too short for you to reach "+
    "the bottom safely and you begin to fall into the darkness below."
  );
  if(this_player()->query_flying()){
    write("Your flight capability allows you to escape from a fall.\n"+
      "You gently sail down to the cave floor.\n");
    tell_room("/d/khojem/new/room/wood4",
      this_player()->query_cap_name()+" gently sails down from the hole above you.\n");
    return 1;
  }
  this_player()->add_hp(-50);
  write("After a short fall you hit solid ground and land in a heap.\n");
  tell_room("/d/khojem/new/room/hole",
    this_player()->query_cap_name()+" falls from above and "+
     "lands flat on his face just beside you.\n");
  return 1;
}
