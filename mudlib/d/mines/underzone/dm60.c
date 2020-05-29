//      From Maxwell's Underground mudlib
//        Office Hallway of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an long hallway with several doors.");
    set("long", 
"You have entered a long hallway. The stone walls have large wooden "
"support pillars every few feet. Several dirty doors lead off from the "
"passage, some of which have large cobwebs forming over them.\n");
    set_exits( ({ UNDER+"dm2"}),
      ({ "south" })
       );
    set_items( ([
       "doors" : "Most of the doors look like they have not been opened "
"recently. Some of them have been boarded up.",
       "cobwebs" : "The spiders are trying to take over the passage.",
       "pillars" : "The strong pillars are the only thing supporting the "
"ceiling.",
      ]) );
       
  set_smell("default", "You can smell the large amount of dust in the air.");
  set_listen("default", "You hear the sounds of mining in the distance.");
}
