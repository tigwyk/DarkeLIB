/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   The passageway opens up into this rather large, sloped chamber.  The 
   floor is pitched at a rather sharp angle, which makes walking somewhat 
   difficult and awkward.  You see a faint light to the north.
    0   
    |   
    @
   / \
  0   0  
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear scratching sounds.");

   set_items( ([

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "north": PATH+"catac100",

                "southwest": PATH+"catac152",

                "southeast": PATH+"catac105",

                ]) );

}

 

void reset() {

   object ob;

 

   ::reset();

   if(!present("skeleton warrior")) {

      ob = new(MON_PATH+"skelwarr");

      ob->move(this_object());

      new("/std/obj/torch")->move(ob);

      ob->force_me("light torch");

   }

}

