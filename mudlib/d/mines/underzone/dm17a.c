//      From Maxwell's Underground mudlib
//      17th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in an underground river.");
    set("long",@ext 
You are floating in an underground river somewhere beneath the 
Under'Drin mining complex. The passage is almost completely filled 
with the dark green water. Your light can only penetrate a few feet 
into the deep murky waves. The icy cold water pushes through the 
passage with a roar and tries to force you downstream.
    0 0  
    |/   
    @--0       
ext);
    set_exits( ({ UNDER+"dm17e",UNDER+"dm17f",UNDER+"dm17b" }),
      ({ "north", "northeast","east" })
      );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "beaches" : "The small beaches border the edge of the river.",
      ]) );
    set_smell("default", "The murky water fills the air with the "
    "smell of wet mold.");
    set_listen("default", "You hear the river dropping over a waterfall "
    "downstream.");
}
int reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"trechin" });
     if(query_property("dead") >= number){
        switch( random(3) ){
               case 0:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob2 = new(mob[0]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob3 = new(mob[0]);
                mob3->move(here);
                mob3->set_property("master_room",master_room); 
                mob4 = new(mob[0]);
                mob4->move(here);
                mob4->set_property("master_room",master_room);
                number = 4;
                break;
               case 1:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob2 = new(mob[0]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob3 = new(mob[0]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                number = 3;
                break;
               case 2:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob2 = new(mob[0]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
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
