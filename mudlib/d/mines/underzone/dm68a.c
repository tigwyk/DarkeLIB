//      From Maxwell's Underground mudlib
//        68th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long",@ext 
You are standing in a small tunnel. The rough walls are jagged and cut 
at sharp angles where the miners dug out gems. There is a large 
opening in the center of the room here. The miners dug a vetical 
tunnel here, leading to a lower section of the mine. There is a large 
ladder in the opening.  
 
        ladder   
    @--0
ext); 
    set_exits( ({ UNDER+"dm68b", UNDER+"dm67" }),
      ({"ladder","east" })
    );
    set_items( ([
    "ladder" : "The wooden ladder is made from Dwarven Oak.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
    set_listen("default", "You hear the sounds of mining in the distance.");
}
