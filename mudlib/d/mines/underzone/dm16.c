//      From Maxwell's Underground mudlib
//      16th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in an underground stream.");
    set("long", 
"You are floating in an underground river. The passage is almost "
"completely filled with the dark green water. Your light can only " 
"penetrate a few feet into the deep murky waves. The icy cold water "
"pushes through the passage with a roar and tries to force you "
"downstream toward a large drop off. Several large rocks, sticking "
"out from the deep water, threaten to smash your body.\n" 
       );
    set_exits( ({ UNDER+"dm15", UNDER+"dm17",UNDER+"dm46" }),
      ({ "shore", "upstream","downstream" })
       );
    set_pre_exit_functions(({"shore"}), ({"mob_check"}) );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "rocks" : "The large rocks stick out only a few inches above"
       "the surface, but could easily break the raft to pieces.",
      ]) );
       
    set_smell("default", "The murky water fills the air with the "
"smell of wet mold."
         );
    set_listen("default", "You hear the river dropping over a waterfall"
" downstream."
          );
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You climb out of the water.");
       return 1;       
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks out over the beach.");
    return 0;
}
