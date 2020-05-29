//      From Maxwell's Underground mudlib
//        43rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large chamber. In the center of "
"the chamber is a large stone tomb.");
    set("long", "You are standing in a large stone chamber. The floor "
"of the chamber is covered with small pieces of rotting cloth. "
"In the center of the chamber is a long marble tomb that extends out "
"from the wall. Surrounding the structure are several black metal pots.");
    set_exits( ({ UNDER+"dm41"}),
      ({ "north" }));
    set_items( ([
"pots" : "The large pots are still filled with a foul smelling liquid."]));
    set_smell("default", "You can smell the foul stench of decay and "
"mold.");
}
void reset() {
    object ob;
   ::reset();
    remove_exit("down");
    if(present("tomb")) {
       present("tomb")->reset();
       return;
    }
    ob = new(UNETC+"tomb1");
    ob->move(this_object());
}

