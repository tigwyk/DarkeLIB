//      From Maxwell's Underground mudlib
//        31st Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int number;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "The tunnel comes to an abupt end here. The ceiling "
"slopes down until only a small tunnel continues to the south. ");
    set("long", 
"The tunnel comes to an abupt end here. The ceiling slopes down "
"until only a small tunnel continues to the south. "
"Large formations have grown from the floor and ceiling. Some "
"of them have connected to form long columns of perfect white "
"mineral desposits. "
"Along the lower part of the western wall is a small opening. It "
"looks like the opening leads into a lower section of the mine."
        );
    set_exits( ({ UNDER+"dm30",UNDER+"dm32" }),
      ({ "north", "hole" })
    );
    set_items( ([
       "wood" : "The moldy wood has DYNAMITE stamped on it.",
      ]) );
       set_smell("default", "Large gusts of cold moldy air are blowing "
"through the hole, hinting at the vast area below.");
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
               case 0:
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

