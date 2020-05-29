//      From Maxwell's Underground mudlib
//        9H Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long", 
"You are standing in a large connection chamber. The thick stone walls "
"stretch to the east and west and also lead into another small chamber "
"to the south.\nThe ceiling is slightly lower in this section of the "
"chamber. You can see a huge crack running along the section right above "
"your head. The miners must have realized that breaking away anymore "
"of the ceiling would have made the area too unstable.");
    set_exits( ({ UNDER+"dm9g",UNDER+"dm9d",UNDER+"dm9e",UNDER+"dm9f",
             UNDER+"dm9i",UNDER+"dm9j" }),
      ({ "west","northwest","north","northeast", "east","south" })
    );
    set_items( ([
     "crack" : "The large crack appears to have grown larger over the time.",
      ]) );
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

