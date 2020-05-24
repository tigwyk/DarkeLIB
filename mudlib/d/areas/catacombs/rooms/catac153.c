/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   Small torches attached to the wall provide enough light for you to
   make out your surroundings.  In a niche in one of the walls is a 
   small statue of a humanoid creature of some kind.
    0   
    |   
    @
   / \
  0   0 
ext);
   set_smell("default", "The air smells of smoke.");
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                "niche":
        "There is a short statue in this niche.",
                "statue":
        "The statue is about two feet tall and depicts a rather nasty-"+
        "looking, dagger-wielding, grin-wearing wight.",
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "north": PATH+"catac114",
                "southwest": PATH+"catac116",
                "southeast": PATH+"catac102",
                ]) );
}
 
void reset() {
   ::reset();
   if(!present("shaggy zombie"))
      new(MON_PATH+"shagzomb")->move(this_object());
   if(!present("silver skeleton"))
      new(MON_PATH+"silvskel")->move(this_object());
}
