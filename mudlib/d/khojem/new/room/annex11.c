//      Wizard:  Khojem
//      annex 11
//      annex11.c

#include <std.h>

inherit ROOM;

void init() {
  :: init();
  add_action("do_drink","drink");
}

void reset(){
  ::reset();
  if(!present("scout") && random(4)) 
    new("/d/khojem/new/mon/elf_scout")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n     \n    \nA wooded path");
    set("long", "You are on a path.  The trees grow "+
      "close around and cut off some of the light from above.\n   0\n   | \n   @   \n     \n    \n"
    );
    add_exit("/d/damned/virtual/room_14_20.world","north");
    add_exit("/d/khojem/new/room/annex9","stream");
    add_invis_exit("stream");
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
    new("/d/khojem/new/obj/stream")->move(this_object());
}


int do_drink(string str) {
  if(!str) {
    notify_fail("What do you want to drink?\n");
    return 0;
  }
  if(str!="water" && str!="stream") {
    return 0;
  }    
  this_player()->add_quenched(5);
  write("You bend down and drink the clear water from the stream.\n");
  say(this_player()->query_cap_name()+" sips water from the stream.\n",
    this_player());
  return 1;
}
