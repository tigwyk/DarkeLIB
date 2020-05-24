
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "all directions. The ground seems to slant towards the middle of the "
   "plateau, and you can see off in the direction of the center, a dark tower."
    " There is a cloud, above this patch of ground, which does not seem to move, like the other clouds above the plateau."
    );
    set_exits( ({  "plat37.c", "plat35.c", "plat33.c", "plat23.c", "alchhut.c"}),
      ({"north", "east", "west", "south", "hut"})
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

 void reset()   {
      ::reset(); 
	new(PLATMON + "ckid")->move(this_object());
      new(PLATMON + "ctmom")->move(this_object());
}
