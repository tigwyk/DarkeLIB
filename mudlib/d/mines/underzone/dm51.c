//      From Maxwell's Underground mudlib
//      51th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing on the west side of the river. A "
"large stone building is to the west of you. The thick walls stretch above "
"you."
     );
    set("long", 
"You are standing on the west side of the river. A large stone building "
"is here. Its stone walls stretch up above you, broken only by a few "
"lighted windows."
       );
    set_exits( ({ UNDER+"dm49",UNDER+"dm53" 
     }),
      ({ "east","door" })
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
