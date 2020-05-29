//      From Maxwell's Underground mudlib
//        73rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("long", "You are on an unstable wooden and metal mine track "
"high above a deep chasm. You can see a thundering river far below you.");
    set("short", 
"You are on an unstable mine track, high above a chasm.");
    set_exits( ({ UNDER+"dm72",UNDER+"dm74"}),
      ({ "up","southeast" })
    );
    set_items( ([

       "track"  : "The polished wood and steel track leads up toward a "
                  "dark tunnel in the distance and further over the chasm "
                  "to the southeast.",
       "river"  : "The river is roaring far below you.",
       "chasm"  : "The steep stone walls lead straight into the icy waves.",
      ]) );
}
void init(){
  ::init();
    if(this_player()->is_player() && (random(100) < 35) )
       call_out("slip_track",2,this_player());       
}
int slip_track(object who){
    tell_player(who,"The track vibrates slightly and you lose you "
        "footing!\nYou slip over the side of the track and fall downward "
        "into the chasm!!\nThe rushing air roars in you ears and you "
        "slam into the icy cold water!\nDarkness closes in on you....\n\n");
     who->move(UNDER+"dm73a");
     return 1;
}
