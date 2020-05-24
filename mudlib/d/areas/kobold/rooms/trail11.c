/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "You are walking on a small dirt path that leads through the plains of "
   "DarkeMud.  To the south lies what seems to be a small village of some "
   "kind, while to the north the path continues.  To the north you also "
   "see some kind of encampment.  There is a %^BOLD%^%^YELLOW%^sign%^RESET%^ here which you should "
   "take a %^BOLD%^%^YELLOW%^look%^RESET%^ at."
   );
   set("night long",
   "It is quite difficult to see anything on this dark night.  You seem to "
   "be walking on a dirt path that winds through the plains of DarkeMud.  "
   "There is faint light to the south, while only darkness lies to the "
   "north, east, and west.  There is a %^BOLD%^%^YELLOW%^sign%^RESET%^ here which you should "
   "take a %^BOLD%^%^YELLOW%^look%^RESET%^ at."
   );
   set_listen("default", "You heard a bird chirping.");
   set_items( ([
                "plains":
       "The grasses of the plains shiver slightly in the wind.",
                ({"village", "light", "south"}):
       "There appears to be some kind of village to the south.",
                "sign":
"\nThe sign reads:\n\n"+
"\t\t\t%^BOLD%^%^RED%^Beware!%^RESET%^\n"+
"\n"+
"\tBy order of the kobold chieftain, no\n"+
"\tkobolds may pass beyond this point.\n"+
"\tBeware of the infidel dwarves who live\n"+
"\tto the north!\n"+
"\nSorry folks, this area has not been implemented yet.\n"+
"   -Duridian\n",
                ]) );
   set_exits( ([
//                "north": "/wizards/duridian/dwarf/trail01",
                "south": PATH+"trail10",
                ]) );
}
 
 
