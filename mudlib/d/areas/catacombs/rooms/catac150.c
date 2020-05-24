/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   The passageway forks here, running off in three directions.  To the 
   south you spy a low-ceilinged room of some sort, while to the 
   northwest the passage continues. 
   As you peer around the room, you notice that something is just not 
   right.  Your body itches slightly and you feel a burning sensation.
  0    
   \   
    @
    |
    0   
ext);
   set_smell("default", "The air smells of rotting corpses.");
   set_listen("default", "You hear moaning.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "northwest": PATH+"catac103",
                "south": PATH+"catac106",
                ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("shaggy zombie")) {
      ob = new(MON_PATH+"shagzomb");
      ob->move(this_object());
      ob->set_skill("necromancy", 65);
      ob->add_spell("rot", "");
      ob->set_spell_level("rot", 3);
      ob->force_me("cast *3 rot");
   }
}
