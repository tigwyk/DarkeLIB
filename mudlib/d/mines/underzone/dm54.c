//      From Maxwell's Underground mudlib
//      54th Room of Dwarf Mining Zone
//      Power Plant Upstairs

#include <std.h>
#include "under.h"
inherit ROOM;
int picture_moved;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "You are standing in a small office. The room is cluttered"
    "with papers and boxes of trash.");
    set("long",@ext 
       You are standing in a small office. The room is cluttered 
    with papers and boxes of trash. Scattered among them are books on 
    mining.\nIn the center of the room is a large oak desk. On the 
    back wall is a large framed picture.
   
    @
        staircase   
ext);
    set_exits( ({ UNDER+"dm53"}),
      ({ "staircase" })
       );
    set_items( ([
       "papers" : "The papers are wadded up and thrown everywhere.",
       "boxes" : "There must be twenty different boxes laying here.",
       "trash" : "The trash had been piled on top of the papers and boxes", 
      ]) );
       
    set_smell("default", "The smell of rotting fruit fills the air.");
    set_listen("default", "You can here the floor vibrating from the noise "
                          "downstairs.");
}
void init(){
    ::init();
       add_action("move_picture","move"); 
       add_action("look_picture","look");
       add_action("read_scroll","read");
       find_object_or_load(UNDER+"dminv");
}
int read_scroll(string str){
    if(str == "scroll" || str == "picture"){
       write("As you eyes glance at the undeciperable language, the words "
       "begin to form  into understandable phrases.\n\n"
"    'During the time of the seige of Montar, the powerful Dwarven Axe of "
"Montar was seperated into three pieces by the great Dwarven Mage "
"Venkart, under order of the Royal Duke of Montar. The three pieces were "
"entrusted to three guardians, summoned from other dimensional "
"realites by Venkart the Mage.\n"
"     Just before the invading forces broke through into "
"the city, the guardians and Venkart were secretly moved from Montar to a "
"sacred temple somewhere deep within the Great Mountains.\n"
"     It was widely believed that the Duke intended to retrieve the axe "
"after reinforcements arrived from the Northern realm. However, they "
"came too late. Montar had been burned to the ground days before, and "
"the location of the Mountain Temple was lost forever in the ashes and "
"blackened stones.'\n\n"
"             'Jencob, Offical Scribe of The City Of Montar\n"
"      May the souls of my fellow Dwarves find peace in the afterlife.'" );
       return 1;
    }
}
       
int look_picture(string str){
     if(str == "picture" || str == "at picture" || str =="scroll"
        || str == "at scroll"){
       write("It is a framed scroll that is obviously very old. The "
       "writing on it is in an ancient Dwarven script. Maybe you should "
       "try reading it.");
       if(picture_moved == 1)
         write("The picture has been moved to one side, revealing a "
               "hidden wall safe!");
       return 1;
     }     
}
int move_picture(string str){
    if(str == "picture"){
      if(picture_moved != 1){
        write("You push the picture aside, revealing a wall safe!");
        if(present("safe",find_object_or_load(UNDER+"dminv") ))
           present("safe",find_object(UNDER+"dminv") )->move(this_object());
        else    
          new(UNETC+"safe")->move(this_object());
        picture_moved = 1;
      }
      else {
        write("You make sure the safe is closed and locked and move the "
              "picture back in front of the safe.");
        if(present("safe"))
          present("safe")->move(UNDER+"dminv");
        picture_moved = 0;
      }
      return 1;
    }
}
void reset(){
object mob;
     ::reset();
     if(!present("rug"))
        new(UNETC+"rug")->move(this_object());
     if(!present("desk"))
        new(UNETC+"desk")->move(this_object());
     if(!present("jenkarb") &&
        !present("jenkarb",find_object_or_load(UNDER+"dm53")) ){
        mob = new(UNMON+"jenkarb");
        mob->move(this_object());
        mob->armour_total_midlevel("helmet,gaunt,bodyhi,leggin");
        mob->weapon_code_midlevel("double");
     }
     return;
}
