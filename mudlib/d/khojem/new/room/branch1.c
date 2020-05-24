//      Wizard:  Khojem
//      hermit branch 1
//      branch1.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "   0\n   | \n   @   \n   | \n   0\nOut on a limb");
    set("long", "The branch is getting narrow here and starting "+
      "to moan under your weight.  You are high above the forest "+
      "floor below you.  A fall from here would hurt.  "+
      "A branch extents south and north.   0\n   | \n   @   \n   | \n   0\n"
    );
    add_exit("htree1","north");
    add_exit("wood4","south");
    set_pre_exit_functions(({"south"}),({"go_south"}));
    set_items(([
        "tree" :
        "This tree is much older than the others that surround you.  "+
        "A spindly, thin rope descends from the foliage above.  "+
        "You doubt such a thin rope can hold all of your weight.",
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
}

int go_south(){
  write("You tightrope your way farther out on the limb.  "+
    "The branch continues to moan and flex under your weight.  "+
    "Oops!  You slip off and fall downward..."
  );
  if(this_player()->query_flying()){
    write("Your flight capability allows you to escape from a fall.\n"+
      "You gently sail down to the forest floor.\n");
    tell_room("/d/khojem/new/room/wood4",
      this_player()->query_cap_name()+" gently sails down from the tree above you.\n");
    return 1;
  }
  this_player()->add_hp(-50);
  write("After a short fall you hit the forest floor and land in a heap.\n");
  tell_room("/d/khojem/new/room/wood4",
    this_player()->query_cap_name()+" falls from above and "+
     "elegantly lands flat on his face beside you.\n");
  return 1;
}
