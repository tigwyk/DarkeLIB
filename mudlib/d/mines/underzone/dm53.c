//      From Maxwell's Underground mudlib
//      53rd Room of Dwarf Mining Zone
//      Power Plant

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "You are standing in a large room inside the stone "
    "building. The polished wood floor is cluttered with assorted "
    "tools and gears.");
    set("long", 
       "You are standing in a large room inside the stone building. The "
    "polished wooden floor is covered with assorted piles of tools and "
    "gears.\nIn the center of the room is a large column with two meshed "
    "gears. There is another set of gears on the wall that is attached "
    "to a pulley and a steel cable. It looks as though the miners are "
    "using the waterwheel to move the mine carts through the mine.\n");
    set_exits( ({ UNDER+"dm51",UNDER+"dm54"}),
      ({ "door","staircase" })
       );
    set_items( ([
       "column" : "The huge column is made from iron and wood.",
       "grears" : "The rotating gears turn effortlessly.",
       "cable" : "The cable is pulled whenever the gears engage.",
       "pulley" : "The steel pulley holds the cable close to the ceiling.",
      ]) );
       
    set_smell("default", "The smell of oil and grease is overpowering.");
    set_listen("default", "The sounds of moving gears fills the room.");
    set_pre_exit_functions(({"door"}), ({"mob_check"}) );
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You walk out through the doorway.");
       return 1;       
    }
    return 0;
}
