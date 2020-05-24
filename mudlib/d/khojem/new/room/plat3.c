//      Wizard:  Khojem
//      plat3
//      plat3.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("guard") && random(2))
    new("/d/khojem/new/mon/elf_guard")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nA wooded platform");
    set("long", "High-up in a tree a wooden platform is lashed together.  "+
      "Small huts are east and west from here.  A much larger hut is to the "+
      "north.  The forest floor is far below.\n   0\n   | \n0--@--0\n   | \n   0\n"
    );
    add_exit("hut5","west");
    add_exit("hut4","east");
    add_exit("foyer","north");
    add_exit("walk3","south");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
        "large hut" :  "In comparison to the other huts you have seen here "+
        "this hut dwarfs the others.  It spans between two large elms.",
     ({ "hut", "huts" }) :
        "The small hut is made of wood and has a thatched roof.",
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
