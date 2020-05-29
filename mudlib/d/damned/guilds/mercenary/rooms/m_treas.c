//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

#include <std.h>
#include <../merc.h>


inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"train_room", "west");
   set("short","The Mercenaries' Public Stores");
   set("long",
"This is the Mercenaries' Treasury.  Any mercenary may store items here, "
"but they are open to use by any other mercenary.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest or locker after using it, "
"or the items may be lost!");
}

