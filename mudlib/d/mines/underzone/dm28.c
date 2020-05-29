//      From Maxwell's Underground mudlib
//        28th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing at the eastern end of the "
"breakdown pile.");
    set("long", 
"You are standing at the eastern end of the breakdown pile. The "
"large boulders block the entire tunnel to the west, except for a small passage "
"that leads up into the middle of the pile of rubble. The carved "
"tunnel, now clear of all but a few boulders, stretchs off to the "
"east. Stacked against the walls of the tunnel are more crates. Some "
"of the crates have been torn apart, leaving only a few rusty nails "
"and busted hinges scattered among the debris." );
    set_exits( ({ UNDER+"dm27",UNDER+"dm29" }),
       ({ "up", "east" }));
    set_items( ([
       "crates" : "The wooden crates are broken and covered with a "
       "white mold."]) );
    set_smell("default", "The dust floating through the air is making "
       "it hard to breathe.");
}
int reset(){
object mob1,mob2,mob3,mob4,master_room,here;
string *mob;
     ::reset();
     master_room = (this_object());
     here = this_object();
     mob = ({ UNMON+"mskel" });
     if(query_property("dead") >= number){
        switch( random(3) ){
           case 0 :
               mob1 = new(mob[0]);
                mob1->move(here);
                mob1->set_property("master_room",master_room);
                mob1->armour_total_midlevel("glove,head,pants");
                mob2 = new(mob[0]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob3 = new(mob[0]);
                mob3->move(here);
                mob3->set_property("master_room",master_room); 
                mob3->armour_total_midlevel("glove,head,pants");
                mob4 = new(mob[0]);
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
                mob2 = new(mob[0]);
                mob2->move(here);
                mob2->set_property("master_room",master_room);
                mob2->armour_total_midlevel("glove,head,pants");
                mob3 = new(mob[0]);
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
                mob2 = new(mob[0]);
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

