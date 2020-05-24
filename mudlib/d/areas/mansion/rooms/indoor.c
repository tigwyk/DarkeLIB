// indoor

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "Inside the foyer");
    set("long", @ext You stand just inside a well decorated mansion.  
      As you look about you you notice you are at the southern end 
      of an enourmous chamber.  To the north lie a long set of  
      stairs.
    0   
    |   
 0--@--0
     leave
      
ext);
    add_exit("frontstairs","north");
    add_exit("outdoor","leave");
    add_exit("swchamber","west");
    add_exit("sechamber","east");

    set_smell("default", "You smell rotting flesh.");
    set_listen("default", "You hear faint scratching.");
}
void reset() {
   ::reset();
   if(!present("scout")) {
      new(A1MON+"s_scout")->move(this_object());
   }
}
