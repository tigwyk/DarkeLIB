//      Wizard:  Khojem
//      path 7
//      path7.c

#include <std.h>

inherit ROOM;

void reset(){
  int coin_flip;
  ::reset();
  coin_flip=random(2);
  if(!present("scout"))
    if(coin_flip) 
      new("/d/khojem/new/mon/elf_scout")->move(this_object());
    else
      new("/d/khojem/new/mon/orc_scout")->move(this_object());
}  



void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@   \n     \n    \nA dark path intersection");
    set("long", "You follow the path to a bend.  "+
      "The trees grow close all around and shroud most of the light "+
      "from above.\n   0\n   | \n0--@   \n     \n    \n"
    );
    add_exit("path6","north");
    add_exit("path3","west");
    set_items(([
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage."+
        "They grow densely all around you.",
     ({ "leaf","leaves" }) :
        "The leaves form a close lattice over your head and don't "
        "allow in much light from above.",
     ({ "trail","path" }) :
        "The trees close in closely to the trail, but you can "+
        "make out the definite signs of a trail or path here.  The "+
        "ground appears worn and the leaves on the ground "+
        "are not as frequent here.  The trail is frequently used.  "
        "Definitely not by woodland creatures only."
    ]));
    set_smell("default", "The dank, moist smell of decaying wood is everywhere.");
    set_listen("default", "The silence around you is numbing.");
}
