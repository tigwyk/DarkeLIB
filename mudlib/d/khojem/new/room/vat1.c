//      Wizard:  Khojem
//      Fire Vat 1
//      vat1.c

#include <std.h>

inherit ROOM;

void init() {
  :: init();
  add_action("do_drink","drink");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   | \n   0\nA firefighter's station");
    set("long", "This small, roofless platform serves one purpose in "+
      "this small, wood-elf village.  It is a central place from "+
      "which fires may be fought.  The forest floor is far below.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("walk6","north");
    add_exit("walk8","south");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
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
    new("/d/khojem/new/obj/vat")->move(this_object());
}

int do_drink(string str) {
  if(!str) {
    notify_fail("What do you want to drink?\n");
    return 0;
  }
  if(str!="water" && str!="vat") {
    return 0;
  }    
  this_player()->add_quenched(5);
  write("You bend down and drink the clear water from the vat.\n");
  say(this_player()->query_cap_name()+" sips water from the vat.\n",
    this_player());
  return 1;
}
