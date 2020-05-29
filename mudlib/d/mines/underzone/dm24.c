//      From Maxwell's Underground mudlib
//        24th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

string *dm_rooms;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small chamber under the breakdown "
                 "pile.");
    set("long", 
"You are standing in a small chamber under the breakdown pile. "
"It appears that the miners reached this area and were unable to "
"continue further to the east. An unusually large boulder dropped "
"right into the center of the passage. You can see several areas "
"on it where the miners tried to crack it and break off chunks. "
"However the task was too great and the miners eventuallly gave up."
  );
    set_exits( ({ UNDER+"dm23"}),
      ({ "west" })
       );
    set_items( (["boulder" : "The large boulder is wedged between the "
"walls of the passage. It would take a lot of force to move it."]) 
       );
   dm_rooms=({"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
              "o","p"});
}
int smoke(string fun) {
    tell_room( UNDER+"dm22",
"A huge explosion echoes through the room and thick smoke pours through "
"the tunnel to the east.\n");
}
int smokey(string fun) {
    set_long("The chamber is filled with thick smoke. You can't see "
"anything. The smoke enters your lungs and causes you to choke.");
    call_out("clear",5,this_player());
    return 1;
}
int clear(string fun) {
   tell_room(UNDER+"dm24",
"The smoke and flames begin to lessen. As you cough on the remaining ash "
"in your lungs, you notice the wreckage before you.\n");
   add_exit(UNDER+"dm25","hole"); 
   set_long(
"You are standing in a rubble filled room. A massive explosion ripped "
"through the room recently. There is thick layer of ash on the floor that "
"is still radiating heat. A large boulder that was in the middle of the "
"passage was split in half, revealing a hole that continues under the "
"rubble pile.");
}
int echo(){
int z,i;   
string u;
  z = 1;
  i = 0;
 tell_room(UNWORK,"You hear a distant explosion..");
 while(z <= 44){
   u = ""+z;
   if(z == 9 || z == 17){
     while(i < sizeof(dm_rooms) ){
       if(i < 10) 
        tell_room(UNDER+"dm9"+dm_rooms[i],"You hear a loud explosion from "
           "somewhere deep in the mine");
        tell_room(UNDER+"dm17"+dm_rooms[i],"You hear a loud explosion from "
           "somewhere deep in the mine");
        i = i+1;
     }
   }
   if(z <= 19){
     tell_room(UNDER+"dm"+u,"You hear a loud explosion from somewhere "
       "deep in the mine");
   }
   if((z >= 20) && (z <= 30) && (z != 24)) {    
     tell_room(UNDER+"dm"+u,"A huge explosion from nearby shakes the "
      "ceiling!!");
   }
   if(z >=31 && z <= 66){
     tell_room(UNDER+"dm"+u,"You hear a loud explosion from somewhere deep "
       "in the mine");
   }
   z = z + 1;
 }
}
void reset() {
    ::reset();
    set("long", 
"You are standing in a small chamber under the breakdown pile. "
"It appears that the miners reached this area and were unable to "
"continue further to the east. An unusally large boulder dropped "
"right into the center of the passage. You can see several areas "
"on it where the miners tried to crack it and break off chunks. "
"However the task was too great and the miners eventuallly gave up."
       );
}
