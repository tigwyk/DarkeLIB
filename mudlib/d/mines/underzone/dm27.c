//      From Maxwell's Underground mudlib
//        27th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are crouched in a small tunnel that stretches under "
         "the breakdown pile.");
    set("long",@ext 
You are crawling in a small tunnel that stretches under the 
breakdown. The passage slopes down further to the east and 
rises into a larger opening above. There are several pieces 
of moldy wood laying in the crawlway. The pieces disentergrate into 
splinters whenever you touch them.
       up
    @
       down         
ext);
    set_exits( ({ UNDER+"dm26",UNDER+"dm28" }),
      ({ "up", "down" })
    );
    set_items( ([
       "wood" : "The moldy wood has DYNAMITE stamped on it.",
      ]) );
       set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
}

