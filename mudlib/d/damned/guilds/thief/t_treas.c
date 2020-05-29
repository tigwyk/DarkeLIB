#include <under.h>
inherit "/std/locker_room";
 
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(UNTHIEF+"thief6", "staircase");
   add_exit(UNTHIEF+"thief7","north");
   set("short","The Thief Treasury");
   set("long",
"This is the Thief Treasury.  Any thief may store items here, "
"but they are open to use by any other thief.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items inside may be lost!");
}
 
