//      From Maxwell's Underground mudlib
//        9E Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a damp mine tunnel somewhere within "
        "the Under'Drin Mining complex.");
    set("long",@ext 
      You are standing in a damp mine tunnel somewhere within the 
      Under'Drin Mining complex. Water slowly rolls down the walls in 
      little streams, soaking the moldy staw that is lining the passage. 
      You can see faint seams of mineral deposits in the walls.
    0   
    |  
    @--0
ext);
    set_exits( ({ UNDER+"dm13",UNDER+"dm15" }),
        ({ "north", "east" }));
    set_items( ([
       "hole" : "The hole in the side wall leads to the surface.",
       "passage" : "This passage leads out of the chamber to somewhere "
       "deeper in the cave.",]));
    set_listen("default", "You can hear the loud roar of rushing water "
       "to the east.");
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
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,head,pants");
                mob4 = new(mob[3]);
                mob4->move(here);
                mob4->set_property("master_room",master_room);
                mob4->armour_total_midlevel("glove,head,pants");
                number = 4;
                break;
               case 1:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,head,pants");
                number = 3;
                break;
               case 2:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
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

