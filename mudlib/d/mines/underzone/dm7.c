//      From Maxwell's Underground mudlib
//        7th Room of Dwarf Mining Zone


#include "under.h"
inherit TRAP;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You have entered some sort of storage area.");
    set("long",@ext 
You have entered some sort of storage area. There are several empty 
wooden shelves leaning against the walls and a couple of crates 
scattered on the cracked stone floor. You can hear the timber support 
beams groan under their heavy load. Most of the beams look like they 
should be replaced. The moist air has rotted the wood and a white 
mold has started to grow on the damper sections.  
       
    @
       arch         
ext);
    set_exits( ({ UNDER+"dm6" }),({ "arch" }) );
    set_items( ([
       "shelves" : "The wooden shelves are empty.",
       "beams" : "The wooden beams are covered in dirt and cobwebs.",
      ]) );

//Trap Code
    set_pre_exit_functions( ({"arch" }), ({"trap_check"}) );
    trap_active = "armed";
    trap_level  = 13;
    trap_type = "Poison Dart";
    trapped_exit = "arch";
    sister_trap = (UNDER+"dm6");
    safe_players = ({});
}

void reset() {
    object chest;
    ::reset();
    if(!present("chest")){      
      chest = new(UNETC"chest");
      chest->move(this_object());
    }
    else {
      chest = present("chest");
      if(!present("pick",chest) ) {
        chest->remove();
        reset();
      }
    }  
    return; 
}
