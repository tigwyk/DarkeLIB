//      From Maxwell's Underground mudlib
//      48th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing on the bank of a large river. A huge "
"waterfall is roaring in front of you.\n" 
     );
    set("long",@ext 
You are standing on the bank of a large river. A huge 
waterfall is roaring in front of you. Thousands of gallons of water 
are falling every second. Cascading down and slamming into the lower 
river.   
        up   
    @    river       
ext);
    set_exits( ({ UNDER+"dm47",UNDER+"dm45" 
     }),
      ({ "river","up" })
       );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
      ]) );
       
    set_smell("default", "The murky water fills the air with the "
    "smell of wet mold."
    );
    set_listen("default", "The roaring sound of the waterfall fills your "
    "ears."
    );
    set_pre_exit_functions( ({"river" }), ({"mob_check"}) );
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You wade into the river.");
       say(this_player()->query_cap_name()+" wades into the river.");
       return 1;       
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks out over the river.");
    return 0;
}
