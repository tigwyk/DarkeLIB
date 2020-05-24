/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

int found = 0;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   This passageway runs west from the entrance to this level of the 
   catacombs and continues to the northwest.  A thin layer of dust 
   covers the floor and walls.  There is a small pile 
   of rocks in one corner of the chamber.
  0    
   \   
    @--0   
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear moaning nearby.");

   set_search("rocks", (: call_other, this_object(), "search_rocks" :) );

   set_items( ([

                ({"rocks", "pile", "pile of rocks"}):

        "There seems to be a pile of normal, nondescript rocks in a corner.",

                ({"walls", "wall", "floor", "dust"}):

        "The walls and floor are covered in a thin layer of dust.",

                ({"torches", "small torches"}):

        "The small torches that are affixed to the wall provide very little light.",

                ]) );

   set_exits( ([

                "northwest": PATH+"catac153",

                "east": PATH+"catac100",

                ]) );

}

 

void search_rocks() {

   object ob;

 

   if(this_player()->query_skill("perception") >= random(50)+25 && found == 0) {

      message("info", "You search the rocks and find a broad sword hidden among them.",

         this_player());

      message("info", this_player()->query_cap_name() +

         " searches the pile of rocks and finds a broad sword hidden among them.",

          this_object(), this_player());

      ob = new("/d/damned/virtual/broad-sword_6.weapon");

      ob->move(this_object());

      found = 1;

   }

   else {

      message("info", "You search between the rocks but find nothing.",

         this_player());

      message("info", this_player()->query_cap_name() +" searches in the pile of rocks.",

            this_object(), this_player() );

   }

   return;

}

