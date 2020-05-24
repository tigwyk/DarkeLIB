//      From Maxwell's Underground mudlib
//        2nd Room of Dwarf Mining Zone

#include "under.h"
inherit TRAP;

string who,name;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short",
"You are standing at the northern end of the entrance tunnel.");
    set("long",@ext
You are now standing at the northern end of the entrance 
tunnel. The air is becoming slightly stuffy. The rough walls are cracked 
and chipped after years of being exposed to the elements. Several lit 
torch stands cast errie shadows on them as the flames flicker back 
and forth in the wind currents.
The floor has deep ruts cut into 
it. The loaded mining carts that pass through here must be very heavy.
    0   
    |   
    @
    |
    0   
ext);
      set_exits(({UNDER+"dme",
    UNDER+"dm2"}),
      ({ "south", "north" })
    );
    set_items( ([
       "stands"   : "The lit torch stands are made of wrapped iron bars.",
       "entrance" : "This passage leads to the exit of the mine.",
       "south"    : "This passage leads to the exit of the mine.",
      ]) );
     call_out("load",1,this_object());  
     set_smell("default", "You can smell the fumes from burning torches.");
     set_listen("default", "You hear the cold wind blowing out the entrance "
     "to the south.");
//Trap Code Variable
    set_pre_exit_functions(({"south" }), ({"trap_check"}) );
    trap_active = "armed";
    trap_type = "Explosive";
    trap_level = 13;
    trapped_exit = "ruts";
    sister_trap = (UNDER+"dme");
    safe_players = ({});

}
void reset(){
   ::reset();
   trap_active = "armed";
}
int load(){    
      (find_object_or_load(UNDER+"dm3"));
      (find_object_or_load(UNDER+"dm4"));
      (find_object_or_load(UNDER+"dm5"));
      (find_object_or_load(UNDER+"dm6"));
      (find_object_or_load(UNDER+"dm8"));
      (find_object_or_load(UNDER+"dm9"));
      (find_object_or_load(UNDER+"dm62"));
      (find_object_or_load(UNDER+"dm63"));
      (find_object_or_load(UNDER+"dm64"));
      (find_object_or_load(UNDER+"dm65"));
      (find_object_or_load(UNDER+"dm66"));
      (find_object_or_load(UNDER+"dm71"));     
}
//void init() {
//int log;
//  ::init();
//  log = monitor();
//}


