//      From Maxwell's Underground mudlib
//        74th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

object here;
void create() {
    ::create();
    set_property("light", -5);
    set_property("indoors", 1);
    set("long", "You are thrashing about in the icy cold river. The "
     "foul smelling water pushes your body like a leaf.\n");
    set("short", 
    "You are trashing about in the icy river.\n");
   set_smell("default","The foul smelling water overpowers you.");
   set_listen("default","All you can hear is the roaring water all around "
              "you.");
   here = this_object(); 
}
void init(){
  ::init();
  call_out("message1",15,this_player());
}
int message1(object who){
   tell_room(here,"\nThe waves pound you under the water!\nYou start to "
    "drown as you body is pulled deeper under the waves!\nSuddenly you "
    "are forced up and thrown choking onto solid ground!\n");
    who->move(UNDER+"dm15");
    tell_room(UNDER+"dm15","\n"+who->query_cap_name()+" is suddenly thrown "
     "out of the water by a large wave and tossed onto the shore!\n",who);
    return 1;
}


