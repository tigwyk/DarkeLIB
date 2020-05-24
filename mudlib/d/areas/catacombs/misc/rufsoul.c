/* Soul of Rufus Tenderfoot coded by Duridian for DarkeMud.  Needed for
   completion of the catacombs quest.  */
 
#include "std.h"
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("Soul of Rufus Tenderfoot");
   set("id", ({"soul_of_rufus_tenderfoot", "magic globe", "magical globe", "globe"}) );
   set("short", "magical globe");
   set("long", "The strange glass globe contains a swirling white gas.");
   set_weight(50);
   set("value", 100);
}
 
