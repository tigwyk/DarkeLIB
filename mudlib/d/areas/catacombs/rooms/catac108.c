/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void init() {

   ::init();

   add_action("catch_string", "say");

}

 

void create() {

   ::create();

   set_property("light", 0);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   You are forced to strain your eyes in order to see your surroundings.  
   The walls shine slightly in the torch light, and you notice some 
   scrawled writing on one of the walls.  A brighter passageway leaves 
   this room to the northwest, while the corridor to the 
   east is quite dark.
  0    
   \   
    @--0  
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear moaning nearby.");

   set_items( ([

                ({"writing", "scrawl", "wall"}):

        "The scrawl reads: \"tanfer emin sonel emin\".",

                ({"walls", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "northwest": PATH+"catac109",

                "east": PATH+"catac129",

                ]) );

}

 

int catch_string(string str) {

   object tp;

 

   tp = this_player();

 

   if(!str)

      return 0;

   if(str != "tanfer emin sonel emin")

      return 0;

   message("info", "%^CYAN%^%^BOLD%^You are transported somewhere!%^RESET%^",

              tp);

   message("info", "%^CYAN%^%^BOLD%^"+tp->query_cap_name()+

              " disappears in a flash of white light!%^RESET%^",

              this_object(), tp);

   switch (random(5)) {

      case 0: tp->move_player(find_object_or_load(PATH+"catac209"));

              break;

      case 1: tp->move_player(find_object_or_load("/d/damned/virtual/room_20_5.world"));

              break;

      case 2: tp->move_player(find_object_or_load("/d/damned/akkad/ak_center"));

              break;

      case 3: tp->move_player(find_object_or_load("/d/damned/virtual/room_9_33.world"));

              break;

      case 4: tp->move_player(find_object_or_load(PATH+"catac100"));

              break;

   }

}

