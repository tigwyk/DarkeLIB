//      Wizard:  Khojem
//      hermit branch 3
//      branch3.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "    \n     \n   @   \n   | \n   0\nOut on a limb");
    set("long", "The branch is getting narrow here and starting "+
      "to moan under your weight.  You are very high above the forest "+
      "floor below you.  A fall from here would kill you.  "+
      "The tree's branch extends southward.\n    \n     \n   @   \n   | \n   0\n"
    );
    add_exit("htree2","south");
    set_items(([
        "tree" :
        "This tree is much older than the others that surround you.",
     ({ "trees", "woods", "growth" }) :
        "The trees are large, healthy trees filled with foliage."+
        "They grow densely all around you.",
     ({ "leaf","leaves", "foliage" }) :
        "The leaves are all around you.",
        "branch" :
        "You think it can hold you."
    ]));
    set_smell("default", "The dank, moist smell of decaying wood is here "+
      "here.  The smell of... maybe rotting corpses is in the still air."
    );
    set_listen("default", "The silence around you is deafening.  "+
      "Occasionally, you hear the sound of battle from a ways off.");
    new("/d/khojem/new/mon/rogue")->move(this_object());
}
