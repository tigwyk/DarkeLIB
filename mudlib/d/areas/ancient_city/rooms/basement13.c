
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
int    amt;
object money;
::create() ;
set_property("light", 0);
set_property("indoors", 0);
add_exit(ROOMS+"basement12.c", "north");
set("short", "The Basement Of An Ancient House");
set("day long", @ext It is dark
    0   
    |   
    @
ext);
set("night long", @ext It is dark
    0   
    |   
    @
ext);
set_smell("default", "There seems to be a lack of any scent");
set_listen("default", "There also seems to be a lack of sound to"); 
amt = random(10)*20+40;
    money = new("std/obj/coins");
money->set_money("silver",amt);
    money->move(this_object());
}

