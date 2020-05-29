//      From Maxwell's Underground mudlib
//        33rd Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short","You are crouched in a small room at the end of the tunnel. "
"The center of the chamber has sunk down, breaking through the ceiling "
"of a room below, and creating a huge hole.");
    set("long", 
"You are crouched in a small room at the end of the tunnel. The "
"center of the chamber has sunk down, breaking through the ceiling "
"of a room below, and creating a huge hole.\nYour feeble light in unable to penetrate very far "
"into the lower level. You think you can see some sort of stone floor "
"about forty feet below.\nA shiny new anchor bolt has been placed in "
"the wall here.\n"
        );
    set_exits( ({ UNDER+"dm32" }),
      ({ "east" })
    );
    set_items( ([
       "hole" : "The hole leads straight down into the darkness below.\n"
                "It looks way too far to jump. You need something to "
                "assist you down.",
       "anchor" : "The anchor consists of a steel rod with a loop at one "
                   "end. The rod has been hammered into the wall.",     
       "bolt"   : "The anchor consists of a steel rod with a loop at one "
                   "end. The rod has been hammered into the wall.",     
      ]) );
       set_smell("default", "The dust floating through the air is making "
"it hard to breathe.");
}
int query_rope_target(string str){
    if(str == "hole")
      return 1;
    else
      return -1;
}
int query_target_tie(string str){
    if(str == 0)
       return 1;
    if(str == "anchor" || str == "bolt")
       return 1;
    return -1;
}
string climb_rope(object player){
    if(file_name(environment(player)) == (UNDER+"dm33")){
       player->move(UNDER+"dm41");
       return "down";
    }
    if(file_name(environment(player)) == UNDER+"unknown")
    return "up";
 return 0;
}

