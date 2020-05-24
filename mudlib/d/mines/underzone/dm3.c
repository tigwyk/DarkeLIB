//      From Maxwell's Underground mudlib
//        3rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light",0);
    set_property("indoors", 1);
    set("short", "You are standing in a small mining tunnel.");
    set("long",@ext 
You are standing in a small tunnel. A set of mining cart tracks 
takes up most of the floor space. You find that you can walk on a 
small path that runs along the side of the track's crossbeams. The 
walls are becoming rougher in texture. The miners evidently didn't 
spend a lot of time carefully digging the tunnel. Every so often a 
sharp rock catches onto your clothing.
  0    
   \   
 0--@
     \
      0      
ext);
    set_exits( ({ UNDER+"dm2",UNDER+"dm4",UNDER+"dm67" }),
      ({ "southeast", "northwest","west" })
    );
    set_items( ([
       "crossbeam*" : "The study wooden crossbeams are spaced every few feet under the track.",
       ]) );
       
//    set_smell("default", "It smells like a new immortal in here.");
//    set_listen("default", "You hear the sounds of code creation.");
}
int reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"miner2",UNMON+"miner3",UNMON+"miner4",UNMON+"miner5" });
     if(query_property("dead") >= number ){
        switch( random(3) ){
               case 0:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob1->weapon_code_midlevel();
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob2->weapon_code_midlevel();
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,head,pants");
                mob3->weapon_code_midlevel();
                mob4 = new(mob[3]);
                mob4->move(here);
                mob4->set_property("master_room",master_room);
                mob4->armour_total_midlevel("glove,head,pants");
                mob4->weapon_code_midlevel();
                number = 4;
                break;
               case 1:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob1->weapon_code_midlevel();
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob2->weapon_code_midlevel();
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,head,pants");
                mob3->weapon_code_midlevel();
                number = 3;
                break;
               case 2:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob1->weapon_code_midlevel();
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob2->weapon_code_midlevel();
                number = 2;
                break;
         }
         set_property("dead",0);
    }
    return 1;
}
int query_number(){
    return number;
}
