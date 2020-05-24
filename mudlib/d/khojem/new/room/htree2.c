//      Wizard:  Khojem
//      hermit tree 2
//      htree2.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   u \n   @   \n   d \n   \nUp a tree");
    set("long", "To your amazement this near slither of a rope is "+
      "holding your weight!  The rope has served you well so far.  "+
      "You are very high above the forest floor below you.  The light "+
      "here is greatly improved as you work your way through the "+
      "foliage.  The taunt rope extends above "+
      "and below you.  A large branch reaches out to the north.\n   0\n   u \n   @   \n   d \n   \n"
    );
    add_exit("htree1","down");
    add_exit("branch3","north");
    add_exit("hermit_hut","up");
    set_items(([
        "rope" :
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
        "The leaves are close about you.  The rope disappears into the "
        "foliage.",
        "branch" :
        "Hey!  It is a part of the tree.  You think it can hold you."
    ]));
    set_smell("default", "The dank, moist smell of decaying wood is here "+
      "here.  The smell of... maybe rotting corpses is in the still air."
    );
    set_listen("default", "You can hear the sound of birds chirping.  "+
      "Occasionally, you hear the sound of battle from a ways off.");
}

