//      From Maxwell's Underground mudlib
//       19th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in a deep underground pool.");
    set("long", 
"You are floating in  a large underground chamber. The river is " 
"flowing from under a large wall upstream. The thick murky water is "
"pouring out at such a fast rate that most of the room is submerged "
"in a deep pool. Alongside the west end of the pool is a large beach.\n"    
        );
    set_exits( ({ UNDER+"dm18", UNDER+"dm20" }),
      ({ "downstream", "beach" }) );
    set_pre_exit_functions( ({"beach" }), ({"mob_check"}) );
    set_items( ([
       "water" : "The murky water has flooded this chamber and formed a"
" large pool.",
       "beach" : "The beach runs alongside the western edge of the pool.",
      ]) );
       
    set_smell("default", "You can smell molding branches and leaves.");
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

