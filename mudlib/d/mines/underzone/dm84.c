//      From Maxwell's Underground mudlib
//        82nd Room of Dwarf Mining Zone


#include <std.h>
#include "under.h"
inherit ROOM;
int number;


void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a large chamber somewhere in the "
"Mining Complex.");
    set("long", 
"You are standing in a large chamber somewhere in the Mining "
"Complex. There are large piles of rocks everywhere. This must be "
"section of the mine where the Dwarves are currently working.\nThe "
"low ceiling looks fairly stable here, providing just enough "
"clearance for a miner to work comfortably.");
    set_exits( ({ UNDER+"dm83"}),
      ({ "tunnel" }) );

    number = 0;

}
reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"miner6",UNMON+"miner7",UNMON+"miner8",
              UNMON+"miner9" });
     if(query_property("dead") >= number ){
//        tell_room(here,"Entering Switch?");
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





