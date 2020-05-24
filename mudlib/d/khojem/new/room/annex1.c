//      Wizard:  Khojem
//      annex1
//      annex1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   l \n   \nA wooded ladder leading to the forest");
    set("long", "The path wanders off to the north.  A large tree is here and high up in "+
      "its branches you see a platform.  A ladder rest against the edge of "+
      "platform.  The trees grow "+
      "close around and cut off some of the light from above.\n   0\n   | \n   @   \n   l \n   \n "
    );
    add_exit("/d/khojem/new/room/annex2","north");
    add_exit("/d/khojem/new/room/walk5","ladder");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
        "ladder" : "A sturdy wooden ladder lashed together with vines.",
        "platform" : "A sturdy wooden platform is lashed into the "+
          "crotch of a nearby tree.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :
        "The trail is worn from frequent use."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}
