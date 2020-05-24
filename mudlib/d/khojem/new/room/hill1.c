//      Wizard:  Khojem
//      hill1
//      hill1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   \n    \n0--@--0\n    \n   \nA steep, hill path");
    set("long", "The trees grow less closely to the trail here and "+
      "allow in much light.  The trail is steep here and winds up a "+
      "steeply-sloped hill.  The trail is bordered to the south "+
      "by an escarpment.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("hill2","east");
    add_exit("trail2","west");
    set_items(([
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :
        "The trail is steep and worn from frequent use.",
     ({ "escarpment", "cliff" }) :
        "The escarpment is almost cliff-like.  Climbing it is impossible "+
        "since it is almost a vertical incline.",
    ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "The woods are quiet and still.");
}

