/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This passageway curves south as it runs from west to east.  The 
   ceiling is quite low, and you are forced to duck slightly to 
   avoid banging your head.  Small puddles of water cover the ground.
  0   0  
   \ /   
    @ 
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "Water drips from the ceiling.");
   set_items( ([
                "ceiling":
       "It is quite low.",
                ({"water", "puddle", "puddles"}):
       "Small puddles of dark water cover the ground.",
               ]) );
   set_exits( ([
                "northwest": PATH+"catac004",
                "northeast": PATH+"catac012",
               ]) );
}

void reset() {
   object ob;
   ::reset();

   if (!present("zombie")) {
      ob = new(MON_PATH+"zombie");
      ob->move(this_object());
   }
}

