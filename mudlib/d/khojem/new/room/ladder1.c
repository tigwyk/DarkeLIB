//      Wizard:  Khojem
//      ladder1
//      ladder1.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("warrior")) {
    new("/d/khojem/new/mon/elf_warrior1")->move(this_object());
    new("/d/khojem/new/mon/elf_warrior1")->move(this_object());
  }
}  

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   \n   l \n   @--0\n     \n    \nA wooded ladder");
    set("long", "The path ends here.  A large tree is here and high up in "+
      "its branches you see a platform.  A ladder rest against the edge of "+
      "platform.  The trees grow "+
      "close around and cut off some of the light from above.\n   \n   l \n   @--0\n     \n    \n"
    );
    add_exit("trail4","east");
    add_exit("plat1","ladder");
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

