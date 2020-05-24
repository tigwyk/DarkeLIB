//      Wizard:  Khojem
//      trail 0
//      trail0.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   | \n   0\nA wooded path");
    set("long", "You are on a north/south path.  The trees grow "+
      "close around and cut off some of the light from above.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("wood5","south");
    add_exit("clearing","north");
    set_items(([
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :
        "The trail is worn from frequent use."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}

