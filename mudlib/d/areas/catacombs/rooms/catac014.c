/* Room coded by Duridian for DarkeMud. */

#include "std.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This small alcove is set apart from the rest of the catacombs.  In 
   one corner of the room is a large mirror that is shattered.  Glass 
   shards cover the floor, and you are careful to avoid the sharp 
   objects.  Strangely, the glass shards are not clear, but jet black.
  0    
   \   
    @
   /
  0    
ext);
   set_smell("default", "The air has a musty smell.");
   set_listen("default", "There is deathly silence.");
   set_items( ([
                ({"mirror", "glass shards", "glass", "shards"}):
       "The mirror is shattered, and glass shards litter the floor.",
                ]) );
   set_exits( ([
                "southwest": PATH+"catac012",
                "northwest": PATH+"catac011",
                ]) );
}

void reset() {
   object ob;
   ::reset();

   if(!present("skeleton")) {
      ob = new(MON_PATH+"skeleton");
      ob->move(this_object());
   }
}

