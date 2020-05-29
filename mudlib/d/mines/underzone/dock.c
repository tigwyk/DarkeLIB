//      From Maxwell's Underground mudlib
//      Mining Camp for Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "You are standing on a long wooden dock, bordering a"
     "silent bay leading out to the sea.\n");
    set("long", 
     "You are standing on a large wooden dock. The long wooden pilars "
     "are spaced out every few feet, sumerged into the cold murky water.\n"
     "You can see the ocean stretching out to the horizon.\n");          
    set_exits( ({ "/d/damned/virtual/room_24_18.world",
                  "/d/damned/virtual/room_24_19.world"}),
      ({ "coast","sea"}) );
    set_items( ([
          "dock" : "The dock is made of long wooden boards.",
          "pillars"  : "The thick pillars look very strong.",
          ]) );
}
void reset(){
  ::reset();
}
int query_water(){
    return 1;
}

