//      From Maxwell's Underground mudlib
//      49th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing on a rope bridge. Directly below you "
"is the roaring river. The waterwheel is slowly turning in the rough water." 
     );
    set("long", 
"You are standing on a rope bridge. Directly below you "
"is the roaring river. The waterwheel is slowly turning in the rough "
"water.\nFurther to the west is a large stone building.\n"
       );
    set_exits( ({ UNDER+"dm45",UNDER+"dm51" 
     }),
      ({ "east","west" })
       );
    set_items( ([
       "water" : "The icy cold water is roaring below you.",
       "bridge" : "The bridge looks fairly sturdy.",
       "waterwheel" : "The huge waterwheel is slowly rotating.",
      ]) );
       
    set_smell("default", "The murky water fills the air with the "
    "smell of wet mold."
    );
    set_listen("default", "The roaring sound of the waterfall fills your "
    "ears."
    );
}
