//      From Maxwell's Underground mudlib
//        Paymaster's Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in the office of the paymaster.");
    set("long", 
"You have entered a small dirty room. The stone walls are covered "
"with hundreds of little scraps of paper and receipts. There is a "
"large desk in the back of the room that is also piled high with "
"a large assortment of papers. Against the other wall is a smaller "
"table with a large balance. Above the table is a painting.");
    set_exits( ({ UNDER+"dm60"}),
      ({ "out" }));
    set_items( ([
       "scale" : "The paymaster must use this to weigh the workers share "
"of the gems",
       "painting" : "This painting is a beutiful forested valley with a "
"lake in the distance. The frame around the painting is made of solid oak. "
" One side of the frame is covered with greasy fingerprints.",
       "desk" : "The desk is almost completely covered with papers and "
"assorted dishware. The paymaster is definitly a sloppy dwarf.",
      ]) );
    set_smell("default", "You can smell the mold growing on the papers.");
    set_listen("default", "Every few seconds you can hear a tool hitting "
"stone.");
}
