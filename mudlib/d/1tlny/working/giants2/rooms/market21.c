#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Marketplace." );
    set( "day long", @EndText
This marketplace is unlike any other you have seen. The size of it
is astounding, just like the citizens. In the middle of the 
marketplace a fountain can be seen and huge walls towers in all 
directions, surrounding the marketplace. To the north you see a road
and many of the citizens seems to be heading in that direction aswell 
as leaving.
EndText
);  

    set( "night long", @EndText 
This marketplace is unlike any other you have seen. The size of it
is astounding. In the middle of the marketplace a fountain can be
seen and huge walls towers in all directions, surrounding the 
marketplace. To the north you see a road.
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("ground","The ground is covered with huge stonebricks.");
    add_item("marketplace","Truely an amazing sight, the ground of the
marketplace is made of gigantic stonebricks. Walls towers in all directions
surrounding the 
area and in the middle of all a fountain can be seen.");
    add_item("fountain","Shaped of solid rock you realize that the
craftsmanship of this fountain is astonishing.");

    set_exits( ({ ROOMS_PATH+"market22", ROOMS_PATH+"market16",
ROOMS_PATH+"village1" }), ({ "east", "south",
"north" }) );     
}
