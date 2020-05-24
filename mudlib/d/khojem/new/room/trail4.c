//      Wizard:  Khojem
//      trail 4
//      trail4.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("warrior") && random(2)) 
    new("/d/khojem/new/mon/elf_warrior1")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   \n    \n0--@--0\n    \n   \nA wooded path");
    set("long", "You are on a east/west path.  The trees grow "+
      "close around and cut off some of the light from above.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("trail3","east");
    add_exit("ladder1","west");
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
