//      Wizard:  Khojem
//      path 3
//      path3.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   | \n   0\nA dark path intersection");
    set("day long", "You follow the winding trail to this point.  "+
      "The trees grow close all around and shroud most of the light "+
      "from above.  The trail splits here in all directions and "+
      "appears more frequently used by others.\n   0\n   | \n0--@--0\n   | \n   0\n"
    );
    set("night long", "You follow the winding trail to this point.  "+
      "The trees grow close all around and shroud most of the night's light "+
      "from above.  The trail splits here in all directions and "+
      "appears more frequently used by others."
    );
    add_exit("path6","north");
    add_exit("path7","east");
    add_exit("path2","south");
    add_exit("path5","west");
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
