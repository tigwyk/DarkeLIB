//      Wizard:  Khojem
//      hole
//      hole.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "   0\n   | \n   @   \n   h \n   \nA deep hole");
    set("long", "You are in an underground cave.  An opening through "+
      "the ceiling above allows in light, but is far too high for you "+
      "to climb up through it.  Dirt walls surround the small cavern "+
      "and the dirt floor is hard and smooth from repeated use.\n   0\n   | \n   @   \n   h \n   \n"
    );
    add_exit("/d/khojem/new/room/orc1","north");
    add_exit("/d/khojem/new/room/hill2","hole");
    add_pre_exit_function("hole","go_hole");
    set_items(([
     ({ "hole","ceiling", "light" }) :
        "The hole through the cavern's ceiling is very high and the "+
        "end of a rope can be seen high above and beyond your reach.",
     ({ "cave","cavern" }) :
        "The cave is roughly twenty feet in diameter and devoid of "+
        "any furniture.",
        "hole" : "The hole is roughly four feet in diameter, but too "
          "high for you to reach.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.",
        "rope" : "The rope is a thick, sturdy rope.  "+
          "It dangles from above and beyond your reach."
    ]));
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
}

int go_hole() {
  if(this_player()->query_flying()){
    write("Your fly up to the hole.\n");
    tell_room("/d/khojem/new/room/hill2",
      this_player()->query_cap_name()+" skillfully flys up from through "+
      "the hole.\n");
    return 1;
    }
  write("If you could fly you might be able to get there.\n");
  return 0;
}
    

