//      From Maxwell's Underground mudlib
//        39th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small chanber. In the center "
"of the chamber is a large Steel Altar.");
    set("long", 
"You have entered a small chamber. Several smashed clay containers "
"are scattered across the floor. In the middle of the room is a large "
"Steel Altar.");
    set_exits( ({ UNDER+"dm36"}),
    ({ "northwest" }));
    set_items( ([
 "containers" : "The ancient clay containers look like they have been "
"broken for a long time."]) );
    set_smell("default", "The chamber reeks of decay and death.");
    new(UNMON+"stguard")->move(this_object());
}
void reset(){
     ::reset();
     if(!present("altar"))
       new(UNQST+"staltar")->move(this_object());
     return;
}

