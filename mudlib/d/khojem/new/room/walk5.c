//      Wizard:  Khojem
//      Walkway 5
//      walk5.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    add_action("read_sign","read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","ladder");
    }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   \n   l \n0--@--0\n    \n   \nA suspended walkway");
    set("long", "You are high above the forest floor on a swinging "+
      "rope bridge.  The bridge serves as a walkway between "+
      "trees.  Each tree has its own platform and the walkways "+
      "link the platforms together to form a small village above "+
      "the forest floor.\n   \n   l \n0--@--0\n    \n   \n"  
    );
    add_exit("walk4","east");
    add_exit("plat4","west");
    add_exit("/d/khojem/new/room/annex1","ladder");
    add_pre_exit_function("ladder","go_ladder");
    set_items(([
        "village" : "Many small huts are built into the trees around you.",
     ({ "swinging rope bridge", "rope bridge", "walkway", "bridge" }) :
        "The walkway is a simple wooden structure made of split logs "+
        "for the base and lashed to strong, sturdy ropes.  Two ropes "+
        "serve as railing so you don't fall.",
     ({ "rope", "ropes" }) : "The ropes appear strong.",
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "platform", "platforms" }) :
          "Sturdy wooden platforms are lashed into the "+
          "crotch of a nearby trees.  This swinging rope bridge "+
          "connects between platforms.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by
them.",
     ({ "forest floor","floor" }) :
        "The ground is far below.  The few leaves down there would do "+
        "little to cushion your landing from a fall from here."
     ]));
    set_smell("default", "The smell of growth and decaying wood is
everywhere.");
    set_listen("default", "You hear the occasional sound of birds
singing.");
    new("/d/khojem/new/obj/sign")->move(this_object());
}

int go_ladder() {
  int xp,lvl;
  lvl = (int)this_player()->query_level(); 
  xp  = (int)this_player()->query_exp();
  if(xp> 4999 || lvl>1) {
    write("Khojem suddenly appears from the shadows and blocks your
exit.\n"+
      "Khojem tells you that you are too experienced to go down the
ladder.\n"+
      "Khojem quickly disappears into the shadows.\n"
    );
    return 0;
  }
  else return 1;
}

int read_sign(string str){
  if(str != "sign") return 0;
  write("The simple, wooden sign reads:\n\n"+
    "Only very low experience players may decend the ladder.\n"+
    "Hey!  They need some mobs to kill.  *shrug*\n");
  return 1;
}

