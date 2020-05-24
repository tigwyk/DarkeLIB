//      From Maxwell's Underground mudlib
//        45rd Room of Dwarf Mining Zone

#include <daemons.h>
#include <std.h>
#include "under.h"
inherit ROOM;
string who,name,here;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short",
"You are standing on a small outcrop next to the roaring waterfall. "
"A long rope bridge extends to the other side of the river.");
    set("long",@ext 
You are now standing on a small ledge next to the waterfall. The noise 
here is almost unbearable. There is a huge waterwheel turning below you. 
The falling water is pushing the rotating paddles.
Further to the west, on the other side of the river, is a large stone 
building. A long rope bridge extends across the water.  
        up   
 0--@
        down    
ext);
    set_exits( ({ UNDER+"dm46",UNDER+"dm49",UNDER+"dm48" }),
      ({ "up", "west","down" })
    );
    set_pre_exit_functions( ({"up" }), ({"mob_check"}));
    set_items( ([
       "bridge"   : "The bridge is made out of twisted rope and wooden "
                    "boards.",
       "waterwheel" : "This huge wheel is slowly rotating under the "
                      "tremendous force of the falling water.",
       "building"    :"The stone and wood building was built on the bank "
                      "of the river. You can see light shining through "
                      "several of its windows",
      ]) );
    set_smell("default", "You can smell the mist from the cold water.");
    set_listen("default", "The waterfall's roar fills the room, interrupted "
"only by an occasional creaking from the waterwheel.");
    number = 0;
}
int reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"miner2",UNMON+"miner3",UNMON+"miner4",UNMON+"miner5" });
     if(query_property("dead") >= number ){
//        tell_room(here,"Entering Switch?");
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
                number = 2;
                break;
         }
         set_property("dead",0);
    }
    return 1;
}
int mob_check(){
    if(this_player()->is_player() || this_player()->is_pet()) {
       write("You climb up the path.");
       return 1;       
    }
    tell_room(environment(this_player()),this_player()->query_cap_name()+
    " looks up the path.");
    return 0;
}



