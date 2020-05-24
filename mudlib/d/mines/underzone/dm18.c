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
    set("short", "You are floating in an underground river.");
    set("long",@ext 
You are floating in an underground river somewhere below the 
Under'Drin Mining complex. The passage is almost completely filled 
with the dark green water. Your light can only penetrate a few feet 
into the deep murky waves. Several large rocks, sticking out from 
the deep water, threaten to smash your body.
The river opens into a larger room upstream.  
 
        upstream
    @
        downstream
           
ext);
    set_exits( ({ UNDER+"dm17o",UNDER+"dm19" }),
      ({ "downstream", "upstream" })
    );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "rocks" : "The large rocks stick out only a few inches above"
"the surface, but could easily break the raft to pieces.",
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
