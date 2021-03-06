#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A Storm-Giant�home." );
    set( "day long", @EndText
You have entered a Storm-Giant home. This place looks even bigger
then you imagined from the outside. The space between the walls and
the height to the roof gives the room the impression of a void that is
further enhanced by the lack of ornaments. In the middle of the room
stands a table with some chairs grouped around it and in the corner
you see some beds.   
EndText
);  
    set( "night long", @EndText 
You have entered a Storm-Giant home. This place looks even bigger
then you imagined from the outside. The space between the walls and
the height to the roof gives the room the impression of a void that is
further enhanced by the lack of ornaments. In the middle of the room
stands a table with some chairs grouped around it and in the corner
you see some beds. Since all furniture seems to be made of solid
stoneblocks you ain't suprised the door was left open. Not much worth
stealing in here. Or even possible.  
EndText
);  
    add_item("house","This house is HUGE.");
    add_item("bed","A very large stone bed.");
    add_item("beds","Four very large stone beds.");
    add_item("table","A large stone table with some chairs grouped around it.");
    add_item("chairs","Some stone chairs grouped around the table.");
    add_item("walls","This house is HUGE.");
    add_item("wall","The wall towers almost 30 feet above you.");
    add_item("roof","The roof seems to be made of stone... hopefully it won't fall in.");
    add_item("door","This enormous stone door stands open.");
    set_exits( ({
ROOMS_PATH+"village4" }), ({
"east" }) );
}
