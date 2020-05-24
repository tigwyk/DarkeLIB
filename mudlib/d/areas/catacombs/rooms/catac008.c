/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "A Large Chamber in Some Catacombs");
   set("long",@ext
   You are standing in the middle of a very large chamber of the 
   catacombs.  Phosphorescent fungus provides a small amount of light, 
   and the light green growth covers the walls and ceiling.  The chamber 
   extends to the north, west, and east, while a small and dark exit 
   lies to the south.
    0   
    |   
 0--@--0
    |
    0   
ext);
   set_smell("default", "You smell something foul.");
   set_listen("default", "You hear the trickling of water.");
   set_items( ([
                "fungus":
       "The light green fungus provides a small amount of light.",
               ({"ceiling", "walls", "wall"}):
       "The walls and ceiling are covered with the fungus.",
               ]) );
   set_exits( ([
                "north": PATH+"catac010",
                "south": PATH+"catac006",
                "west": PATH+"catac009",
                "east": PATH+"catac011",
               ]) );
}
 
void reset() {
   ::reset();
   if(!present("zombie"))
      new(MON_PATH+"zombie")->move(this_object());
}
