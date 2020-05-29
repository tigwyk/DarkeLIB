//      From Maxwell's Underground mudlib
//        9C Room of Dwarf Mining Zone

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
"You are standing in a large connection chamber. The thick stone wall "
"bends to the south here and stretchs to the west. It must have taken "
"the miners a long time to dig such an immense chamber.\nThere is "
"a steep mine track extending down into a lower section of the mine "
"here.");
    set_exits( ({ UNDER+"dm9b",UNDER+"dm9e",UNDER+"dm9f"}),
      ({ "west", "southwest","south" }));

    set_items( ([
       "track"   : "The wood and steel track quickly drops out of site "
                   "into the lower tunnel.",

       "wall"    :"The huge wall looks very strong.",
      ]) );
}
int bring_cart(){

    if(present("fcart")){
     call_out("cart_empty",3,this_object());
     return 1;
    }
    call_out("new_cart",3,this_object()); 
     return 1;
}
int cart_empty(){
      present("tcart")->empty();
      return 1;
}
int new_cart(){
    new(UNETC+"tcart")->move(UNDER+"dm71");
    tell_room(UNDER+"dm71","A large rusty cart rolls into the room.");
    return 1;
}

int reset() {
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
  ::reset();

  if(!present("stand")){
    new(UNETC+"tstand")->move(this_object());  
  }
  if(!present("panel")){
    new(UNETC+"panel")->move(this_object());
  }
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

