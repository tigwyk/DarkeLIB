//      From Maxwell's Underground mudlib
//        9A Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long", 
"You are standing in a large connection chamber. The solid rock wall "
"makes a sharp bend here, stetching to the east and the south.\nThere "
"is a large amount of dirt and straw piled into this section of the "
"chamber. The sweepers must push most of the debris into the corners.");
    set_exits( ({ UNDER+"dm9b",UNDER+"dm9d",UNDER+"dm9e"}),
      ({ "east","south","southeast" })
    );
    set_items( ([
       "dirt" : "There is a large quantity of dirt piled here.",
       "straw" : "The mouldy straw is mixed in with other debris.",
       "debris" : "The debris is fromed from a mixture of things.",
      ]) );
}
void reset() {
  ::reset();
  if(!present("stand"))
    new(UNETC+"tstand")->move(this_object());  
  if(!present("well"))
    new(UNETC+"well")->move(this_object());
  if(!present("trash can"))
    new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
}
