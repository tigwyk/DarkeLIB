//      Wizard:  Khojem
//      hermit tree 1
//      htree1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   \n   u \n   @   \n   d \n   0\nUp a tree");
    set("long", "To your amazement this mere thread is "+
      "holding your weight!  The rope has served you well so far.  "+
      "You are high above the forest floor below you.  The light "+
      "here has somewhat improved.  The taunt rope extends above "+
      "and below you.  A large branch reaches out to the south.\n   \n   u \n   @   \n   d \n   0\n"
    );
    add_exit("wood4","down");
    add_exit("branch1","south");
    add_exit("htree2","up");
    set_items(([
     ({ "rope","thread" }) :
        "A thin, gossamer thread of a rope descend from the foliage above "+
        "and disappears into the shadows below.  You doubt that such a "+
        "a thin rope can carry your weight.",
        "tree" :
        "This tree is much older than the others that surround you.  "+
        "A spindly, thin rope descends from the foliage above.  "+
        "You doubt such a thin rope can hold all of your weight.",
     ({ "trees", "woods", "growth" }) :
        "The trees are large, healthy trees filled with foliage."+
        "They grow densely all around you.",
     ({ "leaf","leaves", "foliage" }) :
        "The leaves form a tight, close lattice over your head and don't "
        "allow in any light from above.  The rope disappears into the "
        "foliage.",
        "branch" :
        "Hey!  It is a part of the tree.  You think it can hold you."
    ]));
    set_smell("default", "The dank, moist smell of decaying wood is here "+
      "here.  The smell of... maybe rotting corpses is in the still air."
    );
    set_listen("default", "The silence around you is deafening.  "+
      "Occasionally, you hear the sound of battle from a ways off.");
}

