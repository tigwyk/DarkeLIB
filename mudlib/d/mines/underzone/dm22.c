//      From Maxwell's Underground mudlib
//        22nd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a rubble filled mining tunnel.");
    set("long", 
"The passage you are standing in now is filled with rocks and "
"large boulders. There must have been a huge cave-in here. The ceiling "
"has deep cuts where large rocks broke off and fell to the floor. There "
"are a couple of broken digging tools laying on the ground. Next to the "
"tools are some shards of glass from a broken lantern.\n" 
"There is a smaller passage to the east that has been dug "
"through the breakdown. It looks like the miners were trying to break "
"through to the other side of the cave-in.\n");
    set_exits( ({ UNDER+"dm21", UNDER+"dm23" }),
      ({ "southwest", "east" }));
    set_items( ([
       "rocks" : "The rocks are scattered around the passage randomly.",
       "tools" : "The tools must have been broken on the heavy rocks "
         "when the miners were clearing the area.",
       "ceiling" : "The ceiling has large cracks and holes. Several rocks "
         "look like they could fall from it at anytime.",
       "glass"  : "The shards of smoke covered glass are spread on the "
         "floor.",
       ]) );
    set_listen("default", "You can hear the rocks creaking above you. "
    "It would probably be a good idea to leave the area as soon as you "
    "can.");
}
