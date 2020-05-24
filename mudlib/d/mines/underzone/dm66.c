//      From Maxwell's Underground mudlib
//      66th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large chamber. A tunnel "
"leads to the east and there are chambers to the north and west.");
    set("long",@ext 
You are standing in a large chamber somewhere in the 
Under'Drin Mining Complex. The walls have deep cuts where the miners 
have dug out the valuable gems and minerals. There are several piles 
of dust and broken shards of gems. 
Another chamber is to the north, the entrance to the chamber is 
blocked by a set of strong steel bars.The tracks wraps into another 
chamber to the south and leads into tunnel to the east.
   
    @--0
ext);
     set_exits( ({ UNDER+"dm65", }),
      ({ "east" })
      );
    set_items( ([
       "cuts" : "The cuts are spread throughout the wall.",
       "track" : "The track shines in the darkness.",
       "walls" : "The cuts are spread throughout the wall.",
       "piles" : "The piles look like there are made of debris swept from "
       "the floor",
      ]) );
}
void reset() {
    object ob,ore;
    ::reset();
    if(present("cart")) return;
    ob = new(UNETC+"cart.c");
    ob->move(this_object());
    ore = new(UNETC+"pore.c");
    ore->move(ob);
}
