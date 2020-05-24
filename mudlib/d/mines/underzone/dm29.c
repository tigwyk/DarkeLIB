//      From Maxwell's Underground mudlib
//        29th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small tunnel that stretches to "
        "the west and the southeast.");
    set("long",@ext 
You are standing in a small tunnel that stretches to the west
and the southeast. The walls are smooth and dry, except for areas 
where the miners were chipping away at some small mineral deposits.
The small gems sparkle as the light reflects off their surfaces.

 0--@
     \
      0       
ext);
    set_exits( ({ UNDER+"dm28",UNDER+"dm30" }),
      ({ "west", "southeast" })
    );
    set_items( ([
       "wood" : "The moldy wood has DYNAMITE stamped on it.",
      ]) );
       set_listen("default", "You can hear rocks falling to the west");
}

