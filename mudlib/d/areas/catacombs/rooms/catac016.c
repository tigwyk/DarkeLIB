/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set("short", "Dark Catacombs");
   set("long",@ext
   This hidden room is located behind the large crack in the large 
   chamber to the southeast.  There are a few bones and rusty weapons 
   here, as well as several shiny silvery metal shards.  Water trickles 
   from the ceiling, and you hear water splashing nearby, although it 
   is difficult to tell from which direction.
         
    @
     \
      0  
ext);
   set_smell("default", "The air smells stale.");
   set_listen("default", "You hear the trickling of water.");
   set_search("default",
        "In the shadows you discover a narrow opening in the north wall.");
   set_items( ([
                "bones":
        "The dried bones seem to contain teeth marks.",
                ({"weapons", "rusty weapons", "rusted weapons"}):
        "The weapons are rusted and useless.",
                "water":
        "The dark water is cool to the touch.",
                ({"metal", "shards", "metal shards"}):
        "The metal shards are silver and very shiny.",
               ]) );
   set_exits( ([
                "southeast": PATH+"catac009",
                "north": PATH+"catac034",
                ]) );
   set_invis_exits( ({"north"}) );
}
 
void reset() {
   object ob;
   ::reset();
 
   if(!present("silver skeleton")) {
      ob = new(MON_PATH+"silvskel");
      ob->move(this_object());
   }
}
