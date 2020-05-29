//      From Maxwell's Underground mudlib
//        9G Room of Dwarf Mining Zone

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
"stretch to the north and bend to the east here.\nYou can see small "
"mineral veins running through the rock here. The shiny veins streak "
"though the chipped stone and sparkle in the light.");
    set_exits( ({ UNDER+"dm9d",UNDER+"dm9e",UNDER+"dm9h",UNDER+"dm9j" }),
      ({ "north", "northeast","east","southeast" }) );
    set_items( ([
       "veins" : "They look like high quality mineral viens.",
      ]) );
}
void reset() {
  ::reset();
  if(!present("stand")){
    new(UNETC+"tstand")->move(this_object());  
  }
}
