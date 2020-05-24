//      From Maxwell's Underground mudlib
//        26th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are crouched in a small crevice under the "
"breakdown.");
    set("long",@ext  
You are crouched down in a small crevice under the breakdown. 
The floor is covered with a thick layer of dust and broken rocks. 
There is some old broken glass spread among the rocks. It looks 
like it was part of an old lantern that was destroyed when the 
ceiling caved in

 0--@
       down           
ext);
    set_exits( ({ UNDER+"dm25",UNDER+"dm27" }),
      ({ "west", "down" })
    );
    set_items( ([
       "glass" : "The smokey glass is shattered among the rocks.",
      ]) );
       set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
}

