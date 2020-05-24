//      From Maxwell's Underground mudlib
//        9J Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

int miner_dead;
void reset() {
object mob;
  ::reset();
  if(miner_dead == 0){ 
    (UNMON+"surveyor")->move(this_object());
//    mob->weapon_code_midlevel();  
    miner_dead = 1;
  }
  if(!present("stand")){
    new(UNETC+"tstand")->move(this_object());  
  }
}
int miner_dying(){ miner_dead = 0; }

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room");
    set("long",@ext 
You are standing in a small chamber adjacent to the large connection 
room. The stone ceiling slopes down here, limiting you movement.
There is another track coming out of a tunnel in the south wall. It looks 
only big enough for a mine cart though.
  0 0 0  
   \|/   
    @
ext);
    set_exits( ({ UNDER+"dm9g",UNDER+"dm9h",UNDER+"dm9i"}),
      ({ "northwest", "north","northeast" })
    );
    set_items( ([
       "ceiling" : "The heavy ceiling is broken in serveral places.",
      ]) );
//    miner_dead = 0;
}
int bring_cart(){

    if(present("fcart")){
     call_out("cart_empty",3,this_object());
     return 1;
    }
    call_out("new_cart",3,this_object()); 
     return 1;
}
int cart_empty(){
      present("fcart")->empty();
      return 1;
}
int new_cart(){
    new(UNETC+"fcart")->move(UNDER+"dm50");
    tell_room(UNDER+"dm50","A large rusty cart rolls into the room.");
    return 1;
}

