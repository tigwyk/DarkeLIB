//      From Maxwell's Underground mudlib
//        13th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing at the bottom of a long tunnel.");
    set("long",@ext 
You are standing at the bottom of a long tunnel. It slopes 
up several hundred feet to a large wooden door. The flames on 
several torches are pushed back and forth as a slight breeze blows 
through the passage to the east. You can hear the sound of water 
flowing nearby. There must be an underground river at the end of the 
this passage. 
  0  
   \   
    @
    | 
    0        
ext);
    set_exits( ({ UNDER+"dm12", UNDER+"dm14" }),
      ({ "northwest", "south" })
    );
    set_items( ([
       "hole" : "The hole in the side wall leads to the surface.",
       "passage" : "This passage leads out of the chamber to somewhere deeper in the cave.",
      ]) );
}       

