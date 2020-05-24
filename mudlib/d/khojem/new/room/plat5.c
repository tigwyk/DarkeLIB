//      Wizard:  Khojem
//      platform 5
//      plat5.c

#include <std.h>

inherit ROOM;

void reset(){
  object mon;
  ::reset();
  if(!present("hawker")) 
    new("/d/khojem/new/mon/elf_hawker")->move(this_object());
  if(!present("commoner"))
    new("/d/khojem/new/mon/commoner")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @--0\n   | \n   0\nA wooded platform");
    set("long", "High-up in a tree a wooden platform is lashed together.  "+
      "This place appears to be a gathering place for the tree-living "+
      "wood-elves.  A place of business is north from here.  "+
      "The forest floor is far below.\n   0\n   | \n   @--0\n   | \n   0\n"
    );
    add_exit("/d/khojem/new/shop/grocery_shop","north");
    add_exit("walk7","south");
    add_exit("walk6","east");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "hut", "huts", "business", "places" }) :
        "They are huts made of wood and have thatched roofs.  "+
        "The frontal facing is open to this gathering place.",
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
