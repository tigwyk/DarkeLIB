#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Training camp." );
    set( "day long", @EndText
Your feet sink deeply into the mud that covers the ground. 
All around you are small groups of Storm-Giants, wrestling 
and pounding on each other with senior trainers inspecting 
them. Obviously some kind of military training. To the south, 
you see a road leading back to the village.
EndText
);  
    set( "night long", @EndText
Your feet sink deeply into the mud that covers the ground.
This area seems empty at this hour. Perhaps it has some kind
of use during the day? To the south, you see a road leading 
back to the village.
EndText
);   
    add_item("mud","It's filthy and disgusting.");
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    set_smell("default", "Dust from the walls fills your lungs, making it hard to breathe.");   
    set_exits( ({
ROOMS_PATH+"camp5",ROOMS_PATH+"camp1",ROOMS_PATH+"camp3" }), ({
"north", "south", "west" }) );
}
