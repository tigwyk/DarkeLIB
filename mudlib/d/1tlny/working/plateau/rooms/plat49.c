
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "front of you, and ends abruptly to the west and north of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
   " There is a large guard tower here, that looks to be at least two stories tall."
    );
    set_exits( ({  "plat36.c", "stower4.c", "plat48.c" }),
      ({"south", "tower",  "west" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
    add_item("tower",  "This is one of the most menacing buildings you have ever seen. Cobwebs cover every nook and crany, and if this building had eyes, it would be staring at you. It pulls at the edges of your mind, begging you to enter.");
  }
