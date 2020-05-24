//      Wizard:  Khojem
//      hermit hut
//      hermit.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	if (!present("hermit")) {
	  new("/d/khojem/new/mon/hermit")->move(this_object());
	}
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "    \n     \n   @   \n   d \n   \nHermit's Treehut");
    set("long", "You have reached a small hut built here in the "+
      "treetops.  The rope which has served you well so far dangles "+
      "off into the darkness below. The hut is well lit and cheerful.  "+
      "The surroundings are clean and well maintained.  The hut "+
      "is sparsely furnished.  It contains only a chair, table, "+
      "hutch, and bed.\n    \n     \n   @   \n   d \n   \n"
     );
    add_exit("htree2","down");
    set_items(([
        "rope" :
        "A thin, gossamer thread of a rope descends below "+
        "and disappears into the foliage.  You doubt that such a "+
        "a thin rope can carry your weight, but experience proves "
        "otherwise.",
        "tree" :
        "This tree is much older than the others that surround you.  "+
        "A spindly, thin rope descends below.  ",
     ({ "trees", "woods", "growth", "treetops" }) :
        "The trees are large, healthy trees filled with foliage.",

     ({ "hut", "room" }) :
        "The Hermit's hut is clean and well-kept.  The roof is "+
        "thatched and a window lets in light from outside.",
     ({ "thatched", "thatch", "roof" }) :
        "The roof is a simple structure made of large leafs from the "+
        "forest nearby.",
        "window" : "The window is a simple opening to the outside.  "+
          "It has no glass to keep the weather from entering the hut.",
        "chair" : "It is a straight-backed, hardwood chair.\n"+
          "It appears very comfortable.",
        "table" : "A simple wooden table.",
        "hutch" : "A wooden hutch.",
        "bed"   : "A soft comfortable bed.  Its sheets are clean.",
    ]));
    set_smell("default", "All around you smell wild flowers in bloom."
    );
    set_listen("default", "You hear the sound of birds chirping.");
}

