//      Wizard:  Myrddin
//      village_20.c
//      June 97

#include "/wizards/myrddin/defs/defs.h"

inherit "/std/room";

void reset(){
  ::reset();
   }  

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Abandoned House");
    set("long",
	"This building looks like a house.  Well, like it used to be a "
              "house before it was abandoned.  Now it just looks mostly "
              "empty except for some junk.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.  However, you cans say it smells "
              "exactly good inside here either.");
    set_listen("default", "The building is quiet.");
    set_items(([
     ({ "junk" }) :
         "Yep, its junk all right.  The remains of a bed frame, old "
         "clothes not even worth taking, some other crude furniture.  "
         "You get the impression that anything of value they couldnt "
         "take with them they buried in the forest before leaving.",
     ({ "clothes" }) :
         "They are old, dirty, moth eaten, and they wouldnt fit you "
         "anyway.  Trust me, you dont want them.",
    ({ "bed", "frame" }) :
         "Its made of wood all right.  It has about as much value as a "
         "couple branches nailed together.   In other words, none.",
     ({ "furniture" }) :
         "Well, it is in better shape then the bed frame, but you cant "
         "see making any money selling it.  Not that there is anyone to "
         "sell it to, unless you actually want to lug it all the way back to "
         "Akkad.",
]));
    set_exits((["west":HIV_ROOMS+"village_10.c"])); 

}

