//      Wizard:  Khojem
//      annex 5
//      annex5.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   \n     \n   @--0\n   | \n   0\nA wooded path");
    set("long", "You are on a path a small hut is to the east. The trees grow "+
      "close around and cut off some of the light from above.\n   \n     \n   @--0\n   | \n   0\n"
    );
    add_exit("/d/khojem/new/room/annex4","south");
    add_exit("/d/khojem/new/shop/still","east");
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
