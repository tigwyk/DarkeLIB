//      Wizard:  Khojem
//      Walkway 8
//      walk8.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n    \n   \nA suspended walkway");
    set("long", "You are high above the forest floor on a swinging "+
      "rope bridge.  The bridge serves as a walkway between "+
      "trees.  Each tree has its own platform and the walkways "+
      "link the platforms together to form a small village above "+
      "the forest floor.\n   0\n   | \n0--@--0\n    \n   \n"  
    );
    add_exit("walk9","east");
    add_exit("plat6","west");
    add_exit("vat1","north");
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
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "forest floor","floor" }) :
        "The ground is far below.  The few leaves down there would do "+
        "little to cushion your landing from a fall from here."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}

