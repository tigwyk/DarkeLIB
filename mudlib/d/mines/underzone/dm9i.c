//      From Maxwell's Underground mudlib
//        9i Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long", 
"You are standing in a large connection chamber. The solid stone walls "
"stretch to the north and west here.\n The southern wall has been "
"carved and rubbed down until it was almost perfectly smooth. Bolted "
"into the wall are two rods, the ends of which are attached to two iron "
"rings.");
    set_exits( ({UNDER+"dm9f",UNDER+"dm9e",UNDER+"dm9h",UNDER+"dm9j" }),
      ({ "north", "northwest","west","southwest" })
    );
    set_items( ([
       "bolts" : "The old bolts are securely placed in the wall.",
       "rings" : "The thick iron rings are worn down a little on "
                 "the edges.",
      ]) );
}
void reset() {
  ::reset();
  if(!present("stand"))
    new(UNETC+"tstand")->move(this_object());  
  if(!present("slave"))
    new(UNMON+"slave")->move(this_object());
}
