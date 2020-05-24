//      Wizard:  Khojem
//      plat6
//      plat6.c

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
    set("short", "   0\n   | \n   @--0\n   | \n   0\nA wooded platform");
    set("long", "High-up in a tree a wooden platform is lashed together.  "+
      "To the south is a larger hut with a sign.  "+
      "The forest floor is far below.\n   0\n   | \n   @--0\n   | \n   0\n"
    );
    add_exit("walk7","north");
    add_exit("/d/khojem/new/shop/pub","south");
    add_exit("walk8","east");
    set_items(([
        "sign" : 
        "The sign reads:  Barfir's Pub & Alehouse",
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "hut", "huts" }) :
        "A larger hut -- made of wood and has a thatched roof.",
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
