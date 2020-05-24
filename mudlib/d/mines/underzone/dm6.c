//      From Maxwell's Underground mudlib
//        6th Room of Dwarf Mining Zone


#include "under.h"

inherit TRAP;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long",@ext 
You are standing in a damp mine tunnel somewhere within the 
Under'Drin Mining complex. Water slowly rolls down the walls in 
little streams, soaking the moldy straw that is lining the passage. 
You can see faint seams of mineral deposits in the walls.
There is an arch to the west, framed by several support beams.
      0  
     /   
    @
   /   arch
  0      
ext);
    set_exits( ({ UNDER+"dm7",UNDER+"dm8", UNDER+"dm5" }),
               ({ "arch", "southwest", "northeast" })
    );
    set_items( ([
       "archy" : "The arch leads into some sort of room.",
       "water" : "There must be several underground springs near the tunnel.",
      ]) );
       
    set_smell("default", "The smell of moldy straw is overwhelming.");
    set_listen("default", "You hear the sounds of mining in the distance.");
//Trap Code
    set_pre_exit_functions( ({"arch" }), ({"trap_check"}) );
    trap_active = "armed";
    trap_level  = 13;
    trap_type = "Poison Dart";
    trapped_exit = "arch";
    sister_trap = (UNDER+"dm7");
    safe_players = ({});
}

void reset() {
    object mon,broom;
    int t;
    ::reset();
    t = 0;
    if(present("sweeper")) mon = present("sweeper");
     else {
        mon = new( UNMON+"sweeper.c" );
        mon->move(this_object());
        mon->armour_total_midlevel();
     } 
    if(present("gloves")) {
      mon->force_me("get gloves");
      mon->force_me("wear gloves");
       }
     else{
      if(!present("gloves",mon)){
       new( UNARM+"gloves")->move(mon);
       mon->force_me("wear gloves");
      }
     }
     if(present("broom")){
       mon->force_me("get broom");
     }
     else{
      if(!present("broom",mon)){
       new(UNWEAP+"broom")->move(mon);
      }
     }
}

