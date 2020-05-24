/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void init() {
   ::init();
   if(this_player()->query_stats("constitution") < random(100))
      this_player()->add_poisoning(this_player()->query_level()+random(20));
}
 
void create() {
   ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set("short", "Dark Dungeon");
   set("long",@ext
   This passageway reeks of a horrible stench, possibly that of rotting 
   flesh, or perhaps that of spoiled food.  You are unsure of where the 
   smell is coming from, but taking a sniff or two might reveal more 
   about the source of the odor.  Twisting corridors run to the north, 
   west, and east from this location.
    0   
    |   
 0--@--0
ext);
   set_smell("default", "There is a funny smell in the air.");
   set_smell("air", (: call_other, this_object(), "smell_air" :) );
   set_listen("default", "You hear moaning nearby.");
   set_items( ([
                ({"walls", "wall", "floor", "dust"}):
        "The walls and floor are covered in a thin layer of dust.",
                ({"torches", "small torches"}):
        "The small torches that are affixed to the wall provide very little light.",
                ]) );
   set_exits( ([
                "north":PATH+"catac117",
                "west":PATH+"catac133",
                "east":PATH+"catac152",
               ]) );
}
 
void reset() {
   object ob;
   ::reset();
   if(!present("giant mummy")) {
      ob = new(MON_PATH+"giant_mummy");
      ob->move(this_object());
      ob->set("aggressive", 0);
      ob->set_moving(0);
   }
}
 
void smell_air() {
   message("info", "%^GREEN%^You take in a deep breath and suddenly realize that it is poison gas that you are smelling!",
       this_player());
   message("info", this_player()->query_cap_name() + " takes a deep breath and smells the air around you.",
       this_object(), this_player());
   this_player()->add_poisoning(10+random(10));
}
