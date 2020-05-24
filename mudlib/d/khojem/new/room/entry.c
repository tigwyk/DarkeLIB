//      Wizard:  Khojem
//      area entry
//      entry.c

#include <std.h>

inherit ROOM;

void reset(){
  object mon;
  ::reset();
  if(!present("merchant")) 
    new("/d/khojem/new/mon/elf_merchant")->move(this_object());
  if(!present("rock"))
    new("/d/khojem/new/obj/rock")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   o \n   \nA wooded path");
    set("day long", "You are on a north/south path.  The trees grow "+
      "all around, but allow a great deal of sunlight through the "+
      "leaves and branches.  It is really pleasant here.  Off to the "+
      "side you see a few squirrels scampering about.  The trail "+
      "extents north from here.  A large rock is to the trail's side.\n   0\n   | \n   @   \n   o \n   \n"
    );
    set("night long", "You are on a north/south path.  The trees grow "+
      "all around, but allow much of the night's light through the "+
      "leaves and branches.  It is really pleasant here.  Off to the "+
      "side you see a few squirrels scampering about.  The trail "+
      "extents north from here.  A large rock is to the trail's side.\n   0\n   | \n   @   \n   o \n   \n"
    ); 
    add_exit("/d/khojem/new/room/path2","north");
    add_exit("/d/damned/virtual/room_13_16.world","out");
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
        "Although the trees are widely scattered about you still can "+
        "make out the definite signs of a trail or path here.  The "+
        "ground appears slightly worn and the leaves on the ground "+
        "are not as frequent here.  The trail appears frequently used."

    ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "The birds are singing in the trees.");
}
