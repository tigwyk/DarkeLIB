//      From Maxwell's Underground mudlib
//      47th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in a large river at the base "
"of an huge waterfall.");
    set("long",@ext 
You are floating in a large pool at the base of a large waterfall. A 
huge wooden waterwheel is slowly rotating in the water near you.
The waterwheel's movement is churning up huge waves. You should get to the 
shore as soon as possible before you drown. 
       
    @    shore      
ext);
    set_exits( ({ UNDER+"dm48",UNDER+"dm16" }),({ "shore","underwater" }) );
    set_invis_exits( ({"underwater"}) );
    set_pre_exit_functions( ({"shore","underwater" }), ({"mob_check",
     "player_check"}) );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "waterwheel" : "The large waterwheel is slowly rotating under the "
"force of the falling water.",
      ]) );
       
    set_smell("default", "The murky water fills the air with the "
    "smell of wet mold."
    );
    set_listen("default", "The roaring sound of the waterfall fills your "
    "ears."
    );
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You climb out of the water.");
       return 1;       
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks out over the shore.");
    return 0;
}
int player_check(){
   if(this_player()->is_player() || this_player()->is_pet()){
     write("Are you crazy? That would be suicidal!");
     return 0;
   }
   else {
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " dives under the frothy waves!");
    return 1;
   }
}
