//      From Maxwell's Underground mudlib
//        7th Room of Dwarf Mining/Crypt Zone

#include <std.h>
#include "under.h"
inherit ROOM;
int x;
object obj;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are in a musty burial chamber. In front of you is "
"a stone burial altar.");
    set("long", "You are standing in a musty burial chamber. Long cobwebs "
"hang down in front of you. There is a stone burial altar here.");
    set_exits( ({ UNDER+"dmc6"}),
      ({ "south" }));
    set_items( ([
    "archway" : "The archway is made of stone, and is covered in mold."]));
    set_smell("default", "You can smell the foul stench of decay and "
"mold.");
   x = 1;
}
void init(){
    ::init();
    add_action("search", "search");
}
int search(string str){
  if((str == "skeleton" || str == "garments") && x == 1
     && present("skeleton")){
    write("You search the rotting garments and find an old bone and gold "
    "necklace.");
    say(this_player()->query_cap_name()+" searches the skeleton and finds "
 "something in the garments.");
  obj = new(UNETC+"bneck");
  obj->move(this_object());
    x = 0;
    return 1;
 }
 write("You find nothing.");
 say(this_player()->query_cap_name()+" searches around, but finds nothing.");  
 return 1;
}
void reset() {
   ::reset();
  if(!present("stand"))
     new(UNETC+"tstand")->move(this_object());
  if(!present("skeleton"))
     new(UNETC+"cskel1")->move(this_object());
  x = 1;
}



