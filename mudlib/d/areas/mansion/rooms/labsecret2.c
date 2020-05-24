// lab secret 2

#include "mansion.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 2);
    set("short", "A secret room");
    set("long", @ext As you look around you see a dark room lit by lanterns 
      secured in the wall.  Someone has broken through the foundation of 
      the house here and started digging beneath a tombstone.  This room 
      looks as though it was built to serve as some sort of a secret 
      crypt.  To the south you can see a revolving wall that seems to 
      only work in one direction.
      
     ladder   
    @
    |
    0
ext);

    add_item("foundation","The foundation is dug up.");
    add_item("lantern","The lantern flickers from a nearby draft.");
    add_item("wall","The wall to the south seems to lead to push out from "+
      "the inside and lead to darkness.");
    add_exit("labsecret","ladder");
    add_exit("understairs","south"); 

    set_smell("default", "You smell earth and soil.");
    set_listen("default", "You hear nothing.");
}
void reset() {
  object mon;
   ::reset();
   if(!present("ranger")) 
      new(A1MON+"ranger")->move(this_object());
   if(!present("tombstone")) 
      new(A1OBJ+"tombstone")->move(this_object());
}
