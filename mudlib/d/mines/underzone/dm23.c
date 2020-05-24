//      From Maxwell's Underground mudlib
//        23rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are crawling in a small tunnel under the "
"breakdown.");
    set("long",@ext 
You are crawling through a small passage under the breakdown. 
The sharp rocks under you tear at your clothing and skin. The air 
quickly fills with dust as you pull yourself along. Soon you find 
your visiblity is reduced to a few feet. As you continue to pull 
yourself through the cramped enclosure you can see a small 
opening to the east and the western breakdown entrance to the west.

 0--@--0        
ext);
    set_exits( ({ UNDER+"dm22",UNDER+"dm24" }),
      ({ "west", "east" })
    );
    set_items( ([
       "rocks" : "The jagged rocks stick up from the passage floor.",
      ]) );
       set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
}
