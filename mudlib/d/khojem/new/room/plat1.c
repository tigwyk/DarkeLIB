//      Wizard:  Khojem
//      plat1
//      plat1.c

#include <std.h>

inherit ROOM;

int no_exit() { return 1;}

void init() {
    ::init();
    if(this_player()->chk_my_mon()) {
      add_action("no_exit","ladder");
    }
}

void reset(){
  ::reset();
  if(!present("guard") && random(2))
    new("/d/khojem/new/mon/elf_guard")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   \n   l \n0--@--0\n    \n   \nA wooded platform");
    set("long", "High-up in a tree a wooden platform is lashed together.  "+
      "A ladder rest against the platform's edge.  The forest floor is "+
      "far below.\n   \n   l \n0--@--0\n    \n   \n"
    );
    add_exit("/d/khojem/new/room/walk1","east");
    add_exit("/d/khojem/new/room/walk9","west");
    add_exit("/d/khojem/new/room/ladder1","ladder");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
        "ladder" : "A sturdy wooden ladder lashed together with vines.",
        "platform" : "A sturdy wooden platform is lashed into the "+
          "crotch of a nearby tree.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "forest floor","floor" }) :
        "The ground is far below.  The few leaves down there would do "+
        "little to cushion your landing from a fall from here."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}
