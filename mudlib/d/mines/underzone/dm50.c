//      From Maxwell's Underground mudlib
//      50th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in a small room somewhere in the mine "
"complex. There is a single mine track that begins here and runs through "
"a hole in the wall in front of you.");
    set("long",@ext 
You are standing in a small carved room somewhere in the mine complex. 
The dirty room is filled with debris and broken pieces of ore and rocks. 
A single mine track begins here and runs out of the room through a hole 
in the wall in front of you. Above the hole is an old sign.

    @    passage
ext);
    set_exits( ({ UNDER+"dm68e" }),
      ({ "passage" })
       );
    set_items( ([
       "sign" : "The old sign has 'Area 61' written on it.",
       "track" : "The old mine track is covered in grim. There are a "
"couple of sand bags at the end of it to keep the cart from rolling off.",
       "sand bags" : "The large bags are blocking the end of the track.",
       "hole" : "The hole is just large enough for the mine cart. Going "
       "into it would be deadly because you might get crushed by a cart."
      ]) );
       
    set_smell("default", "You smell mold and decay in the dusty air."
         );
    set_listen("default", "You hear the sounds of mining in the distance"
" and the occasional sound of a mine cart rolling by."
          );
    set_pre_exit_functions( ({"passage" }), ({"chest_check"}) );
    set_property("no teleport", 1);
    set_property("no summon", 1);
}
void reset() {
string here;
   ::reset();
//   here=file_name(environment(this_object()));
    set("long", 
"You are standing in a small carved room somewhere in the mine complex. "
"The dirty room is filled with debris and broken pieces of ore and rocks. "
"A single mine track begins here and runs out of the room through a hole " 
"in the wall in front of you. Above the hole is an old sign.\n");
 if(!present("panel")) {
    new(UNETC+"panel")->move(this_object());
 }
 if(!present("dynocrate")){
    new(UNETC+"dcrate")->move(this_object());   
 }
}
int chest_check(){
int crate_present,y,z;
object *inv;
   inv = all_inventory(this_player());
   y = sizeof(inv);
   z = 0;
   crate_present = 0;
   while(z < y){
      if(present("dynocrate",this_player()) || present("dynocrate",inv[z]))       
         crate_present = 1;
       z = z + 1;     
    }
    if(crate_present == 1) {
     write("The crate your carrying is too big to fit into the passage.");
     return 0;
    }
    else
      write("You walk into the passage.");
    return 1;
}

