/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",
   "This is another narrow passageway of the catacombs.  You are forced "
   "to duck your head occasionally, in order to avoid from hurting "
   "yourself on the stalactites."
   );
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "You hear tapping and rattling to the east.");
   set_items( ([ ]) );
   set_exits( ([
                "northwest": PATH+"catac019",
                "south": PATH+"catac030",
                ]) );
}
