/* Room coded by Duridian for DarkeMud. */

 

#include "std.h"

inherit ROOM;

 

void create() {

   ::create();

   set_property("light", 1);

   set_property("indoors", 1);

   set("short", "Dark Dungeon");

   set("long",@ext
   You are standing at the base of a staircase that leads upwards, into 
   darkness.  Unlike the level above, this room and the corridors that 
   lead away from it are not of nature's construction.  The walls, 
   floor, and ceiling are made of polished granite and are cold to the 
   touch.  It would appear that this part of the catacombs was long ago 
   transformed into a dungeon of sorts.  As you gaze down the four 
   corridors that lead away from this room, you notice that they twist 
   and turn a lot, in every direction.
    0   
    |   up   
 0--@--0
    |
    0   
ext);

   set_smell("default", "The air smells of smoke.");

   set_listen("default", "You hear an occasional laugh.");

   set_items( ([

                ({"stairs", "staircase"}):

         "The stairs head up, to the first level of the catacombs.",

                ({"wall", "walls", "ceiling", "floor", "stone", "granite"}):

         "The walls, ceiling, and floor are made of polished granite.",

                ({"corridors", "corridor"}):

         "The hallways lead away from this room.",

                ]) );

   set_exits( ([

                "north": PATH+"catac101",

                "south": PATH+"catac104",

                "west": PATH+"catac102",

                "east": PATH+"catac103",

                "up": PATH+"catac027",

                ]) );

   new(MISC_PATH+"fountain")->move(this_object());

}

 

void reset() {

   ::reset();

   if(!present("tattered paper"))

      new(MISC_PATH+"tatpaper")->move(this_object());

}

 

int no_exit() { return 1; }

 

void init() {

   ::init();

 

   if(this_player()->chk_my_mob())

      add_action("no_exit", "up");

   add_action("do_drink", "drink");

}

 

int do_drink(string str) {

   if(!str) {

      notify_fail("What do you want to drink?\n");

      return 0;

   }

   if(str != "water" && str != "fountain") {

      return 0;

   }

   this_player()->add_quenched(5);

   write("You bend down and drink the clear water from the fountain.\n");

   say(this_player()->query_cap_name()+" gulps water from the fountain.\n",

         this_player());

   return 1;

}

 

