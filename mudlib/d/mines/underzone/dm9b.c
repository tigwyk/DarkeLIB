//      From Maxwell's Underground mudlib
//        9B Room of Dwarf Mining Zone


#include "under.h"
inherit TRAP;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long",@ext 
You are standing in a large connection chamber. The strong stone walls 
stretch to the west and east, pitted and scraped from years of abuse. The 
dirty floor is covered with gravel and clumps of straw. 
A passage leads off to to the east.\nA large mine track has been built here. 
It leads into the northern tunnel and extend southwest toward another 
part of the chamber.
    0   
    |   
 0--@--0
   /|\
  0 0 0
ext);
    set_exits( ({ UNDER+"dm8",UNDER+"dm9c",UNDER+"dm9a",UNDER+"dm9d",
        UNDER+"dm9e",UNDER+"dm9f" }),
      ({ "north", "east","west","southwest","south","southeast" }) );
    set_items( ([
       "track" : "The old track has been worn down by the heavy carts.",
      ]) );
//Trap Code
    set_pre_exit_functions( ({"north" }), ({"trap_check"}) );
    trap_active = "disarmed";
    trap_level  = 13;
    trap_type = "Poison Dart";
    trapped_exit = "straw";
    sister_trap = (UNDER+"dm8");
    safe_players = ({});
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
