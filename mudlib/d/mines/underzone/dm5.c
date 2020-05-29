//      From Maxwell's Underground mudlib
//          5th Room of Underground Zone

#include <std.h>
#include "under.h"
inherit ROOM;
inherit LOGGER;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a mining tunnel.");
    set("long", 
"You are standing in a damp mine tunnel somewhere within the "
"Under'Drin Mining complex. Water slowly rolls down the walls in "
"little streams, soaking the moldy staw that is lining the passage. "
"You can see faint seams of mineral deposits in the walls." 
     );
    set_exits( ({ UNDER+"dm4",UNDER+"dm6" }),
      ({ "northeast", "southwest" })
    );
    set_items( ([
       "water" : "There must be several underground springs near the tunnel.",
       "staw"  : "The moldy staw is slippery and stuck to the cracked floor.",
      ]) );
       

}
void init() {
int log;
  ::init();
  log = monitor();
}

