//      Wizard:  Khojem
//      annex 8
//      annex8.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("scout") && random(4)) 
    new("/d/khojem/new/mon/elf_scout")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "    \n     \n   @   \n   |* \n   0 0\nA wooded path");
    set("long", "You are on a path.  The trees grow "+
      "close around and cut off some of the light from above.\n    \n     \n   @   \n   |* \n   0 0\n"
    );
    add_exit("/d/khojem/new/room/annex7","south");
    add_exit("/d/khojem/new/room/annex9","southeast");
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
