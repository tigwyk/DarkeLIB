//      From Maxwell's Underground mudlib
//          Generic Room for Dwarf Mining Zone

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
     set("short", "Mining tunnel.");
     set("long", @ext You are standing in a mining tunnel.
      
        workroom   
    @
        entrance   
ext);
    set_exits( ({ "/wizards/maxwell/workroom", "/wizards/maxwell/underzone/dme" }),
      ({ "workroom", "entrance" })
    );
    set_items( ([
       "water" : "There must be an underground spring near here.",
       "straw" : "The moldy straw sticks to the stone floor.",
      ]) );
}
