//      From Maxwell's Underground mudlib
//      Mining Camp for Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit "/std/vault";
inherit LOGGER;
string *allowed_players;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "You have entered a small clearing under a large rock "
"outcropping. There is some sort of camp here. ");
    set("long", 
"You have entered a small clearing under a large rock outcropping. " 
"There is some sort of camp here. Several large leather tents have "
"been set up, circling a campfire. There are oak barrels stacked "
"next to the tents and an assortment of digging tools. "
"As you walk toward the back end of the camp you see that a large "
"tunnel has been dug into the mountain side. A strong steel gate "
"blocks the tunnel entrance.\n"
"A large sign has been bolted to the gate.\n"

       );         
    set_exits( ({ "/d/damned/virtual/room_70_13.world",UNDER+"dme"}),
      ({ "mountains","entrance"})

    );
//    set_pre_exit_functions(({"entrance" }), ({"player_check"}) );
    allowed_players = ({"maxwell","sagan","vytek"});
//    set_door("gate", UNDER+"dme", "entrance", 0);
 set_items( ([
          "campfire" : "The campfire is smoldering.",
          "barrels"  : "The barrels are filled with assorted trash.",
          "tents" : "The leather tents are stained dark from the harsh "
                    "weather.",
          "tunnel" : "The tunnel is dark and silent.",
          "tools" : "Most of the tools look like they need major repairs.",
//          "gate" : (: call_other, this_object(), "look_at_door" :),
          "sign" : 


("\n"
  "/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\n"
  "| O                                     O  |\n"  
  "|            Under'Drin Mines              |\n"
  "|                                          |\n"         
  "|        Visitors are Not Welcome!         |\n"
  "|                                          |\n"
  "|       Trespassers will be Punished!      |\n" 
  "| O                                     O  |\n"
 "\\                                          /\n"
  " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ")]) );

//set_string("gate", "close", "You pull against the rusted hinges "
//"until the gate swings shut with a loud clank.\n"); 
//    set_string("gate", "open", "You hear the rusted hinges creak as "
//"you push open the gate.\n");   
}
//void look_at_door() {
//   if(query_open("gate")) write("The gate has been pushed open.");
//   else write("The gate is tightly shut.");
//}
void reset(){
  ::reset();
  //set_open("gate",0);
  if(!present("skull"))
     new(UNETC+"spike2")->move(this_object());
}
int player_check(){
   if(this_player()->is_player()){
     if((member_array(this_player()->query_name(),allowed_players)) != -1){
       this_object()->monitor();
       write("Security Lock Passed. Welcome to Under'Drin Mines\n");
       return 1;
     }
     else {
       write("The mines are currently closed to all players cept testers.");
       return 0;  
     }
   }
   return 1;
} 




