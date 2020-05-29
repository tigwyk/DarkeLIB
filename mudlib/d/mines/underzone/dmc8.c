//      From Maxwell's Underground mudlib
//        8th Room of Dwarf Mining/Crypt Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are in a musty burial chamber. In front of you is "
"a large stone burial altar.");
    set("long", "You are standing in a musty burial chamber. Long cobwebs "
"hang down in front of you. There is a stone burial altar here.");
    set_exits( ({ UNDER+"dmc6"}),
      ({ "north" }));
    set_items( ([
    "archway" : "The archway is made of stone, and is covered in mold."]));
    set_smell("default", "You can smell the foul stench of decay and "
"mold.");
}
void reset() {
   ::reset();
  if(!present("stand"))
     new(UNETC+"tstand")->move(this_object());
  if(!present("case"))
     new(UNETC+"case")->move(this_object());
}




