//      From Maxwell's Underground mudlib
//      52th Room Supply Room

#include <std.h>
#include "under.h"
inherit ROOM;
int items;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("long", "You are standing in a large chamber. Huge wooden shelves "
"line the walls, filled with assorted mining supplies. You can see long "
"cobwebs hanging down from the ceiling.\n"); 
    set("short", 
"You are standing in a small supply room. Large shelves line the walls.\n");
    set_exits( ({ UNDER+"dm65" 
     }),
      ({ "south" })
       );
    set_items( ([
       "cobwebs" : "The long cobwebs hang down in dark strands.",
       "walls" : "The mine walls are smooth and solid.",
      ]) );
       
    set_smell("default", "The air smells musty."
    );
    set_listen("default", "You hear the sounds of mining in the distance."
    );
    items = random(5);
}
void init() {
    ::init();
    add_action("check_shelf","look at"); 
    add_action("check_shelf","look");
    add_action("search_shelf","search");
}
int check_shelf(string str){
    if(str == "shelf"){
       if(items >= 1)
        write("The wooden shelf is cluttered with debris and strange "
        "objects.");
       else
        write("The wooden shelf is bare.");
       return 1;
    }
}
int search_shelf(string str){
  if(str == "shelf" || str == "shelves"){
    if(items >= 1){
      switch(random(3)){
       case 0: write("You find a bag of gems.");
               new(UNETC+"gems")->move(this_player());
               break;
       case 1: write("You find a large pick hidden on the shelf.");
               new(UNWEAP+"pick")->move(this_player());
               break;
       case 2: write("You find a small pile of copper coins.");
               this_player()->add_money("copper",random(40));
               break;
      }
      say(this_player()->query_cap_name()+" searches the "+str);
      items = items - 1;
      return 1;
    }
  }
}
void reset(){
   ::reset();
   items = random(4);
   if(!present("bart"))
     new(UNMON+"bart")->move(this_object());
   if(!present("chart"))
     new(UNETC+"chart")->move(this_object());
   if(!present("stand")){
     new(UNETC+"tstand")->move(this_object());
     if(present("bart"))
        present("bart")->force_me("light stand");
   }
} 

