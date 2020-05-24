//      Wizard:  Khojem
//      path 2
//      path2.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   | \n   0\nA wooded path");
    set("day long", "You are on a north/south path.  The trees grow "+
      "close around and start to cut off the light above. "+
      "Off to the side you see a few squirrels scampering about.  "+
      "The trail extends southward and starts to wind about the "+
      "trees to this point.\n   0\n   | \n   @   \n   | \n   0\n"
    );
    set("night long", "You are on a north/south path.  The trees grow "+
      "close around and start to cut off the night's light above. "+
      "Off to the side you see a few squirrels scampering about.  "+
      "The trail extends southward and starts to wind about the "+
      "trees to this point."
    );
    add_exit("entry","south");
    add_exit("path3","north");
    set_items(([
     ({ "squirrel","squirrels" }) :
        "Two gray squirrels appear to be playing tag.  They chase each "+
        "other back and forth through and around the trees.  They keep "+
        "there distance from you and are much too quick for your attack "+
        "or magic capabilities.",
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :

        "The trees close in closely to the trail, but you can "+
        "make out the definite signs of a trail or path here.  The "+
        "ground appears slightly worn and the leaves on the ground "+
        "are not as frequent here.  The trail is infrequently used "
        "so possibly the woodland creatures use it occasionally."

    ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}

