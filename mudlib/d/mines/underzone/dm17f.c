//      From Maxwell's Underground mudlib
//      17th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are floating in an underground river.");
    set("long",@ext 
You are floating in an underground river somewhere beneath the 
Under'Drin mining complex. The passage is almost completely filled 
with the dark green water. Your light can only penetrate a few feet 
into the deep murky waves. The icy cold water pushes through the 
passage with a roar and tries to force you downstream.
  0 0 0  
   \|/   
 0--@--0
   /|\  
  0 0 0      
ext);
    set_exits( ({ UNDER+"dm17e", UNDER+"dm17i",UNDER+"dm17j",UNDER+"dm17k",
                  UNDER+"dm17g",UNDER+"dm17c",UNDER+"dm17b",UNDER+"dm17a"}),
      ({ "west", "northwest","north","northeast","east","southeast","south",
          "southwest" })
      );
    set_items( ([
       "water" : "The icy cold water chills you to the bone.",
       "beaches" : "The small beaches border the edge of the river.",
      ]) );
    set_smell("default", "The murky water fills the air with the "
    "smell of wet mold.");
    set_listen("default", "You hear the river dropping over a waterfall "
    "downstream.");
}
void reset(){
object ob;
  ::reset();
  ob = new("/wizards/maxwell/objects/mon/trechin");
  ob->move(this_object());
  return;
}  
