//      From Maxwell's Underground mudlib
//        Office One of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a cluttered office.");
    set("long", 
"You have entered a cluttered office. The room is covered in assorted "
"dusty papers and tattered documents. Evidently the miners have more "
"important matters to deal with than cleaning.\n");
    set_exits( ({ UNDER+"dm60"}),
      ({ "out" })
       );
    set_items( ([
       "door" : "It is a large oak door."
      ]) );
       
  set_smell("default", "You can smell the large amount of dust in the air.");
  set_listen("default", "You hear the sounds of mining in the distance.");
}
