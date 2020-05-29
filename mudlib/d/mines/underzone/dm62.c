//      From Maxwell's Underground mudlib
//      62nd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "You are floating in an underground river.");
    set("long", 
"You are standing in a cramped mine tunnel somewhere in the "
"Under'Drin Mine Complex. The rough walls slope down and sink into the "
"thick debris covering the floor. The wide steel track takes up most of "
"the available walking space.");
    set_exits( ({ UNDER+"dm9d",UNDER+"dm63" }),
      ({ "east", "west" })
      );
    set_items( ([
       "debris" : "Crushed rock and straw is covering the floor.",
       "track" : "The track shines in the darkness.",
      ]) );
}
int reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
    if(!present("cougar"))
       new("/wizards/maxwell/objects/mon/cougar2")->move(this_object());

     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"miner6",UNMON+"miner7",UNMON+"miner8",
              UNMON+"miner10" });
     if(query_property("dead") >= number ){
//        tell_room(here,"Entering Switch?");
        switch( random(2) ){
               case 0:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,hat,pants");
                mob1->weapon_code_midlevel();
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,helmet,pants");
                mob2->weapon_code_midlevel();
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,hat,pants");
                mob3->weapon_code_midlevel();
                mob4 = new(mob[3]);
                mob4->move(here);
                mob4->set_property("master_room",master_room);
                mob4->armour_total_midlevel("glove,helmet,pants");
                mob4->weapon_code_midlevel();
                number = 4;
                break;
               case 1:
                mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,hat,pants");
                mob1->weapon_code_midlevel();
                mob2 = new(mob[1]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,helmet,pants");
                mob2->weapon_code_midlevel();
                mob3 = new(mob[2]);
                mob3->move(here);
                mob3->set_property("master_room",master_room);
                mob3->armour_total_midlevel("glove,hat,pants");
                mob3->weapon_code_midlevel();
                number = 3;
                break;

         }
         set_property("dead",0);
    }
    return 1;
}




