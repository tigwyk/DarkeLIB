// lab secret

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 2);
    set("short", "A secret passage");
    set("long", @ext This secret passage from the lab seems to be some 
      sort of escape route, weaving through the walls of the house.  
      There is a crack in the west wall leading back to the lab, and 
      a ladder leading through the floor into darkness below.
       
     ladder   
    @
crack   
    
ext);

    add_item("ladder","The ladder seems strong enough to hold you.");
    add_exit("lab3","crack");
    add_exit("labsecret2","ladder"); 

    set_smell("default", "You smell nothing");
    set_listen("default", "You hear nothing.");
}
