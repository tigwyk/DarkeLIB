//      Wizard:  Khojem
//      annex 3
//      annex3.c

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
    set("short", "     0\n    / \n0--@   \n     \n    \nA wooded path");
    set("long", "You are on a path.  The trees grow "+
      "close around and cut off some of the light from above.\n     0\n    / \n0--@   \n     \n    \n "
    );
    add_exit("/d/khojem/new/room/annex2","west");
    add_exit("/d/khojem/new/room/annex10","northeast");
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
