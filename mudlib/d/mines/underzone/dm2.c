//      From Maxwell's Underground mudlib
//        2nd Room of Dwarf Mining Zone


#include <std.h>
#include "under.h"
inherit ROOM;

int x;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short",
"You are standing in a dark chamber somewhere in the mine.");
    set("long",@ext 
You are standing in a dark chamber surrounded by  mine carts, barrels 
and a couple of dirty burlap bags. A set of rusty mine cart tracks stretch 
into a dusty tunnel to the northwest. The entrance tunnel is to the 
south.
  0   
   \   
    @
    |
    0
ext);
    x = 1;
    set_exits( ({ "dm1","dm3"}),
               ({ "south", "northwest"}));
    set_items( ([
       "carts" : "Some of the steel mining carts are half filled with " 
       "assorted minerals.",
       "tracks" : "The tracks are used to steer the mining carts through "
       "the mine tunnels.",]));
    new( UNETC+"mcart")->move(this_object());
}
void reset() {
 object mon,mon2,pack,donk,broom,gems,bag,cart,ore;
 int y;
 ::reset();
   if(!present("miner")) {
     mon = new( UNMON+"miner1");
     mon->move(this_object());
     mon->armour_total_midlevel("head,pants");
     mon->weapon_code_midlevel();
   }
   if(!present("donkey")) {    
     donk = new(UNMON+"donkey");
     donk->move(this_object());
     bag = new(UNETC+"spack");
     bag->move(donk);
     new(UNETC+"torch")->move(bag);
     new(UNETC+"gems")->move(bag); 
     new(UNETC+"torch")->move(bag);     
     bag->toggle_closed();
   }

}
