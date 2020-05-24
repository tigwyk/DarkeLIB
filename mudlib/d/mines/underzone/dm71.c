//      From Maxwell's Underground mudlib
//        71st Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an underground room somewhere "
"in the mining complex. A mine track drops out of sight to the west.");
    set("long",@ext 
You are standing at the begining of a small tunnel that stretches to 
east. There is a large mine track here that lowers out of site to 
the west.
 
    @--0
ext);
    set_exits( ({ UNDER+"dm81"}),
      ({ "east" })
    );
}
int bring_cart(){

    if(present("tcart")){
     call_out("cart_empty",3,this_object());
     return 1;
    }
    call_out("new_cart",3,this_object()); 
     return 1;
}
int cart_empty(){
      present("tcart")->empty();
      return 1;
}
int new_cart(){
    new(UNETC+"tcart")->move(UNDER+"dm9c");
    tell_room(UNDER+"dm9c","A large rusty cart rolls into the room.");
    return 1;
}

void reset() {
  ::reset();
  if(!present("stand")){
    new(UNETC+"tstand")->move(this_object());  
  }
  if(!present("panel")){
    new(UNETC+"panel")->move(this_object());
  }
  if(!present("tcart")){
    new(UNETC+"tcart")->move(this_object());
  }
}
