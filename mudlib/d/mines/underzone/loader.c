//      From Maxwell's Underground mudlib
//        2nd Room of Dwarf Mining Zone

#include <std.h>
#define UNDER "/wizards/maxwell/underzone/dm"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short",
"You are standing at the nothern end of the loader room.");
    set("long",
"You are now standing at the northern end of the loader room."
    );
    set_exits( ({ "/wizards/maxwell/underzone/dme", 
"/wizards/maxwell/underzone/dm2" }),
      ({ "south", "north" })
    );
    set_items( ([
       "stands"   : "The lit torch stands are made of wrapped iron bars.",
       "entrance" : "This passage leads to the exit of the mine.",
       "south"    : "This passage leads to the exit of the mine.",
      ]) );
}
int load(){
    
      (find_object_or_load(UNDER+"3"));
      (find_object_or_load(UNDER+"4"));
      (find_object_or_load(UNDER+"5"));
      (find_object_or_load(UNDER+"6"));
      (find_object_or_load(UNDER+"8"));
      (find_object_or_load(UNDER+"62"));
      (find_object_or_load(UNDER+"63"));
      (find_object_or_load(UNDER+"64"));
      (find_object_or_load(UNDER+"65"));
      (find_object_or_load(UNDER+"66"));
       (find_object_or_load(UNDER+"71"));
}

