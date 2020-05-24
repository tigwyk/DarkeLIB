/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   object money;

 

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   You are forced to duck your head as you enter this low-ceilinged 
   chamber.  A few scraps of clothing lie on the ground here, probably 
   the remains of some long-dead adventurer.  There are a few bones on 
   the ground here as well, and appear to be humanoid in nature.  
   Openings at the northern and western extremities of the room lead 
   to other parts of the catacombs.
    0   
    |   
 0--@ 
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear moaning nearby.");

   set_items( ([

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ({"scraps", "clothing"}):

        "The pile of clothing scraps is filthy and putrid.",

                ({"bone", "bones"}):

        "The bones are probably from an elf's or high-man's corpse.",

                ]) );

   set_exits( ([

                "north": PATH+"catac150",

                "west": PATH+"catac105",

                ]) );

}

 

void reset() {

   object ob;

   ::reset();

   if(!present("skeleton")) {

      ob = new(MON_PATH+"skeleton");

      ob->move(this_object());

      if(!present("torch")) {

         new("/std/obj/torch")->move(ob);

         ob->force_me("light torch");

      }

   }

}

 

